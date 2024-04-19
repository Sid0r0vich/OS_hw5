#include "kernel/types.h"
#include "user.h"
#include "kernel/param.h"

int main(int argc, char* argv[]) {
	if (argc < 3) {
		fprintf(2, "command must have two arguments!\n");
		return -1;
	}

	int time = atoi(argv[2]);

	if (!strcmp(argv[1], "SYSCALL")) {
		setlogtimer(LOGSYSCALLON, time);
	}
	else if (!strcmp(argv[1], "INTERRUPT")) {
		setlogtimer(LOGINTERRUPTON, time);
	}
	else if (!strcmp(argv[1], "TRAP")) {
		setlogtimer(LOGTRAPON, time);
	}
	else if (!strcmp(argv[1], "EXEC")) {
		setlogtimer(LOGEXECON, time);
	}

	return 0;
}
