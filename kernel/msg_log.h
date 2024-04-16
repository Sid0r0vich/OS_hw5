#define INT_MAX 0b01111111111111111111111111111111

struct logtimers {
	struct spinlock lock;
	int syscall;
	int interrupt;
	int trap;
	int exec;
};
