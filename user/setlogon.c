#include "kernel/types.h"
#include "user.h"
#include "kernel/param.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		fprintf(2, "command must have one argument!\n");
		return -1;
	}

	if (!strcmp(argv[1], "LOGSYSCALL")) {
		setlogon(LOGSYSCALLON);
	}
	else if (!strcmp(argv[1], "LOGINTERRUPT")) {
		setlogon(LOGINTERRUPTON);
	}
	else if (!strcmp(argv[1], "LOGTRAP")) {
		setlogon(LOGTRAPON);
	}
	else if (!strcmp(argv[1], "LOGEXEC")) {
		setlogon(LOGEXECON);
	}

	return 0;
}
