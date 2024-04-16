#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "syscall.h"
#include "defs.h"
#include "msg_log.h"

struct spinlock logflagslock;
char logflags = 0b0100;

struct logtimers logtmr;

void logtimersinit() {
	acquire(&logtmr.lock);
	logtmr.syscall = INT_MAX;
	logtmr.interrupt = INT_MAX;
	logtmr.trap = INT_MAX;
	logtmr.exec = INT_MAX;
	release(&logtmr.lock);
}

void sys_setlogon(void) {
	char flag;
	argstr(0, &flag, 1);

	acquire(&logflagslock);
	logflags |= flag;
	release(&logflagslock);
}

void sys_setlogoff(void) {
	char flag;
	argstr(0, &flag, 1);

	acquire(&logflagslock);
	logflags &= flag;
	release(&logflagslock);
}

void sys_setlogtimer(void) {
	char flag;
	argstr(0, &flag, 1);

	int time;
	argint(1, &time);
	time += ticks;

	acquire(&logtmr.lock);
	switch (flag) {
		case LOGSYSCALL:
			logtmr.syscall = time;
			break;
		case LOGINTERRUPT:
			logtmr.interrupt = time;
			break;
		case LOGTRAP:
			logtmr.trap = time;
			break;
		case LOGEXEC:
			logtmr.exec = time;
			break;
	}
	release(&logtmr.lock);
}

void sys_dellogtimer(void) {
	char flag;
	argstr(0, &flag, 1);

	acquire(&logtmr.lock);
	switch (flag) {
		case LOGSYSCALL:
			logtmr.syscall = INT_MAX;
			break;
		case LOGINTERRUPT:
			logtmr.interrupt = INT_MAX;
			break;
		case LOGTRAP:
			logtmr.trap = INT_MAX;
			break;
		case LOGEXEC:
			logtmr.exec = INT_MAX;
			break;
	}
	release(&logtmr.lock);
}

int checktimer(char flag) {
	acquire(&logtmr.lock);
	switch (flag) {
		case LOGSYSCALL:
			return ticks < logtmr.syscall;
		case LOGINTERRUPT:
			return ticks < logtmr.interrupt;
		case LOGTRAP:
			return ticks < logtmr.trap;
		case LOGEXEC:
			return ticks < logtmr.exec;
	}
	release(&logtmr.lock);

	return -1;
}
