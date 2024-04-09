#include "kernel/msg_buffer.h"
#include "user.h"

int main() {
	char* buf = malloc(sizeof(char) * MSGBUFLEN);
	if (dmesg((char*)buf) < 0) {
		fprintf(2, "dmesg error!\n");
		return -1;
	} else {
		printf(buf);
	}
	
	return 0;
}
