#include "kernel/types.h"
#include "user.h"
#include "kernel/param.h"

int main(int argc, char* argv[]) {
	if (argc < 3) {
		fprintf(2, "command must have two arguments!\n");
		return -1;
	}

	int time = atoi(argv[2]);

	if (!strcmp(argv[1], "LOGSYSCALL")) {
		setlogtimer(LOGSYSCALLON, time);
	}
	else if (!strcmp(argv[1], "LOGINTERRUPT")) {
		setlogtimer(LOGINTERRUPTON, time);
	}
	else if (!strcmp(argv[1], "LOGTRAP")) {
		setlogtimer(LOGTRAPON, time);
	}
	else if (!strcmp(argv[1], "LOGEXEC")) {
		setlogtimer(LOGEXECON, time);
	}

	return 0;
}
