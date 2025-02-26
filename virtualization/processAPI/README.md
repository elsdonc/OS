### program functionality
#### forkWithoutWait.c
1. calls fork
2. child process: prints pid of child
3. parent process: prints pids of parent and child

#### forkWithWait.c
1. calls fork
2. child process: prints pid of child
3. parent process: waits for child to terminate, then prints pids of parent and child

### compile instructions
```
gcc -o forkWithoutWait forkWithoutWait.c
gcc -o forkWithWait forkWithWait.c
```

### run instructions
```
./forkWithoutWait
./forkWithWait
```

### expected output
```
./forkWithoutWait
```
non deterministic behavior, where parent process could print before child process

```
./forkWithWait
```
deterministic behavior where child process prints before parent process every time because the call to `wait()` suspends the parent process until its child terminates or a signal is received