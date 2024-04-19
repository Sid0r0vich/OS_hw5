#include "kernel/types.h"
#include "user.h"
#include "kernel/param.h"

int main(int argc, char* argv[]) {
	char flags =  getlogflags();

	printf("log flags: ");
	if (flags & 0b1000) printf("EXEC ");
	if (flags & 0b0100) printf("TRAP ");
	if (flags & 0b0010) printf("INTERRUPT ");
	if (flags & 0b0001) printf("SYSCALL ");
	printf("\n");
}


