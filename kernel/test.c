#include "msg_buffer.h"
#include "defs.h"
#include <stdarg.h>

extern msgbuff msgbuf;

void assert(int pred) {
	if (!pred) {
		printf("Assertion failed!");
		exit(1);
	}
}
