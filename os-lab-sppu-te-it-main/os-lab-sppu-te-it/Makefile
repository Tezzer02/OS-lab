
CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lpthread -lrt

all: a1a a1b a2a a2b a3a a3b a4a a4b a5a a5b a6a a6b a7a a7b a8a a8b

a1a: Assignment1/A1a_LinuxCommands_basic.c
	$(CC) $(CFLAGS) $^ -o $@
a1b: Assignment1/A1b_AddressBook_advanced.c
	$(CC) $(CFLAGS) $^ -o $@
a2a: Assignment2/A2a_ProcessControl_basic.c
	$(CC) $(CFLAGS) $^ -o $@
a2b: Assignment2/A2b_OrphanZombie_advanced.c
	$(CC) $(CFLAGS) $^ -o $@
a3a: Assignment3/A3a_FCFS_basic.c
	$(CC) $(CFLAGS) $^ -o $@
a3b: Assignment3/A3b_SJF_nonpreemptive_advanced.c
	$(CC) $(CFLAGS) $^ -o $@
a4a: Assignment4/A4a_Mutex_basic.c
	$(CC) $(CFLAGS) $^ -o $@ -lpthread
a4b: Assignment4/A4b_ProducerConsumer_advanced.c
	$(CC) $(CFLAGS) $^ -o $@ -lpthread -lrt
a5a: Assignment5/A5a_Bankers_basic.c
	$(CC) $(CFLAGS) $^ -o $@
a5b: Assignment5/A5b_DeadlockDetection_advanced.c
	$(CC) $(CFLAGS) $^ -o $@
a6a: Assignment6/A6a_FIFO_basic.c
	$(CC) $(CFLAGS) $^ -o $@
a6b: Assignment6/A6b_LRU_advanced.c
	$(CC) $(CFLAGS) $^ -o $@
a7a: Assignment7/A7a_FIFO_basic_writer.c
	$(CC) $(CFLAGS) $^ -o $@
a7b: Assignment7/A7b_SharedMemory_advanced.c
	$(CC) $(CFLAGS) $^ -o $@ -lrt
a8a: Assignment8/A8a_FCFS_basic.c
	$(CC) $(CFLAGS) $^ -o $@
a8b: Assignment8/A8b_SSTF_advanced.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f a1a a1b a2a a2b a3a a3b a4a a4b a5a a5b a6a a6b a7a a7b a8a a8b
