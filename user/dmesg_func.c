#include "kernel/types.h"
#include "kernel/msg_buffer.h"
#include "user.h"

int dmsg() {
	char* buf = malloc(sizeof(char) * (MSGBUFLEN + 1));
	buf[MSGBUFLEN] = 0;
	if (dmesg((char*)buf) < 0) {
		fprintf(2, "dmesg error!\n");
		return -1;
	} else {
		printf(buf);
	}

	return 0;
}
