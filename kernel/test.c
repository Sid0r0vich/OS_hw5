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

	msgadd("This is hird message!");
	assert(msgbuf.end == 21 + 14 + 22);

	for (int i = 0; i < 814; ++i) {
		msgadd("Spam1234!");
	}
}
