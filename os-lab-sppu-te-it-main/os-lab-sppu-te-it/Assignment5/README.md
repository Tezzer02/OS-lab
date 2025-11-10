# Assignment 5

Contains two programs: basic and advanced versions.

## Files
- A5a_..._basic.c  : Basic implementation
- A5b_..._advanced.c : Advanced implementation

## How to compile
```bash
gcc A5a_*.c -o a5a
gcc A5b_*.c -o a5b -lpthread -lrt  # if needed
```

## Sample output (short)
Example: Banker prints 'Safe sequence: P0 P1 ...' if system is safe, else 'Not safe'.
