# Assignment 7

Contains two programs: basic and advanced versions.

## Files
- A7a_..._basic.c  : Basic implementation
- A7b_..._advanced.c : Advanced implementation

## How to compile
```bash
gcc A7a_*.c -o a7a
gcc A7b_*.c -o a7b -lpthread -lrt  # if needed
```

## Sample output (short)
Example: FIFO writer/reader exchange messages using /tmp/myfifo_demo; Shared memory writes and reads the same message.
