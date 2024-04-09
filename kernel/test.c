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

void test_msg() {
	msgadd("Hello, world!");
	pr_msg("msg #%d: message!", 1);
	acquire(&msgbuf.lock);
	assert(msgbuf.end == 21 + 14);
	release(&msgbuf.lock);

	msgadd("Third message!");
	assert(msgbuf.end == 21 + 14 + 15);

	printf("%s\n", msgbuf.buf);

	for (int i = 0; i < 1; ++i) {
		msgadd("Spam1234!");
	}
	msgadd("0");
}
