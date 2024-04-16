#include "kernel/types.h"
#include "user.h"

#include "kernel/msg_buffer.h"

int main() {
	for (int i = 0; i < 3; ++i) fork();
	sleep(1);
	
	return 0;
}
