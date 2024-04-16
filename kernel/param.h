#define NPROC        64  // maximum number of processes
#define NCPU          8  // maximum number of CPUs
#define NOFILE       16  // open files per process
#define NFILE       100  // open files per system
#define NINODE       50  // maximum number of active i-nodes
#define NDEV         10  // maximum major device number
#define ROOTDEV       1  // device number of file system root disk
#define MAXARG       32  // max exec arguments
#define MAXOPBLOCKS  10  // max # of blocks any FS op writes
#define LOGSIZE      (MAXOPBLOCKS*3)  // max data blocks in on-disk log
#define NBUF         (MAXOPBLOCKS*3)  // size of disk block cache
#define FSSIZE       2000  // size of file system in blocks
#define MAXPATH      128   // maximum file path name
#define NBUFPG	 	 2	 // count of buffer pages

#define LOGSYSCALLON 0b0001
#define LOGINTERRUPTON 0b0010
#define LOGTRAPON 0b0100
#define LOGEXECON 0b1000

#define LOGSYSCALLOFF 0b1110
#define LOGINTERRUPTOFF 0b1101
#define LOGTRAPOFF 0b1011
#define LOGEXECOFF 0b0111

#define LOGSYSCALL 0b0001
#define LOGINTERRUPT 0b0010
#define LOGTRAP 0b0100
#define LOGEXEC 0b1000
