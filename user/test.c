#include "kernel/types.h"
#include "kernel/msg_buffer.h"
#include "user.h"

void assert(int pred) {
	if (!pred) {
		printf("Assertion failed!");
		exit(1);
	}
}

void test_msg() {
	int p[2];
	if (pipe(p) < 0) {
		fprintf(2, "pipe error!");
		exit(1);
	};
	
	int pid = fork();
	if (pid > 0) {
		close(p[0]);
		close(1);
		dup(p[1]);
		close(p[1]);
		
		int res = dmsg();
		if (res < 0) {
			fprintf(2, "dmesg error!");
			exit(1);
		}
	} else if (!pid) {
		close(p[1]);

		char* buf = malloc(sizeof(char) * (MSGBUFLEN + 1));
		buf[MSGBUFLEN] = 0;
		int res = read(p[0], buf, MSGBUFLEN);
		
		close(p[0]);
		if (res < 0) {
			fprintf(2, "read error!");
			exit(1);
		}

		assert(buf[0] == 's' && buf[1] == '1');
	} else {
		fprintf(2, "fork error!");
		exit(1);
	}
}

int main() {
	char* argv[] = {"/ws", "user/test.c"};
	exec("/wc", argv);
	
	return 0;
}
