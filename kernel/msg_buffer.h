#include "param.h"
#include "types.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"

#define MSGBUFLEN (NBUFPG * PGSIZE)
// #define MSGBUFLEN 512

struct msgbuff {
	struct spinlock lock;
	
	char buf[MSGBUFLEN];
	int begin;
	int end;
};

typedef struct msgbuff msgbuff;
