#include "kernel/types.h"
#include "user.h"
#include "kernel/param.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		fprintf(2, "command must have one argument!\n");
		return -1;
	}

	if (!strcmp(argv[1], "SYSCALL")) {
		setlogoff(LOGSYSCALLOFF);
	}
	else if (!strcmp(argv[1], "INTERRUPT")) {
		setlogoff(LOGINTERRUPTOFF);
	}
	else if (!strcmp(argv[1], "TRAP")) {
		setlogoff(LOGTRAPOFF);
	}
	else if (!strcmp(argv[1], "EXEC")) {
		setlogoff(LOGEXECOFF);
	}
	else fprintf(2, "wrong flag: %s!\n", argv[1]);

	return 0;
}
