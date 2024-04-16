#include "kernel/types.h"
#include "user.h"
#include "kernel/param.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		fprintf(2, "command must have one argument!\n");
		return -1;
	}

	if (!strcmp(argv[1], "LOGSYSCALL")) {
		setlogoff(LOGSYSCALLOFF);
	}
	else if (!strcmp(argv[1], "LOGINTERRUPT")) {
		setlogoff(LOGINTERRUPTOFF);
	}
	else if (!strcmp(argv[1], "LOGTRAP")) {
		setlogoff(LOGTRAPOFF);
	}
	else if (!strcmp(argv[1], "LOGEXEC")) {
		setlogoff(LOGEXECOFF);
	}

	return 0;
}
