# Assignment 2

Contains two programs: basic and advanced versions.

## Files
- A2a_..._basic.c  : Basic implementation
- A2b_..._advanced.c : Advanced implementation

## How to compile
```bash
gcc A2a_*.c -o a2a
gcc A2b_*.c -o a2b -lpthread -lrt  # if needed
```

## Sample output (short)
Example: Process control prints child and parent messages; orphan demo shows changed PPID; zombie demo shows child exit before parent reaps.
