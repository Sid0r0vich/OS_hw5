#include "kernel/types.h"
#include "user.h"

int main() {
	char* argv[] = {"/ws", "user/test.c"};
	exec("/wc", argv);
	
	return 0;
}
