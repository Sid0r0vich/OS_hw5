#include "kernel/types.h"
#include "user.h"
#include "kernel/param.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		fprintf(2, "command must have one argument!\n");
		return -1;
	}

	if (!strcmp(argv[1], "SYSCALL")) {
		dellogtimer(LOGSYSCALLON);
	}
	else if (!strcmp(argv[1], "INTERRUPT")) {
		dellogtimer(LOGINTERRUPTON);
	}
	else if (!strcmp(argv[1], "TRAP")) {
		dellogtimer(LOGTRAPON);
	}
	else if (!strcmp(argv[1], "EXEC")) {
		dellogtimer(LOGEXECON);
	}

	return 0;
}
