# Virtualizing Memory

### program functionality
1. allocates memory for a pointer
2. prints the process id (pid) and the address of the pointer
3. sets the value of the pointer to 0
4. loops 5 times, pauses 1 second each loop, and prints the pid and pointer value

### compile instructions
```
gcc mem.c
```

### run instructions
```
./a.out & ./a.out &
```
'&' allows us to run the program concurrently in the background

### expected results
```
prompt> ./a.out & ./a.out &
[1] 24113
[2] 24114
(24113) address pointed to by p: 0x200000
(24114) address pointed to by p: 0x200000
(24113) p: 1
(24114) p: 1
(24113) p: 2
(24114) p: 2
(24113) p: 3
(24114) p: 3
(24113) p: 4
(24114) p: 4
(24113) p: 5
(24114) p: 5
```

### actual results
- If the addresses are different, this is due to address space layout randomization (ASLR), a memory-protection strategy that prevents buffer overflow attacks by randomizing the location where executables are loaded into memory.
##### temporarily disable ASLR on linux:
```
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
```
##### re-enable ASLR on linux:
```
echo 2 | sudo tee /proc/sys/kernel/randomize_va_space
```

### analysis
- Each process has its own private virtual address space, which gives the illusion that we're modifying the same address in memory.
- Memory references within one process doesn't affect the address space of other processes.
