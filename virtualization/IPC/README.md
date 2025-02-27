### program functionality

1. calls fork twice, connecting standard output of 1 child to the standard output of another child via a pipe
2. unused read/write ends of the pipe are closed in child processes to unblock other processes from reading/writing to the pipe
3. child 1 writes to the pipe, child 2 reads from the pipe and prints the content in it

### compile instructions

```
gcc piping.c
```

### run instructions

```
./a.out
```

### expected output
reading from pipe: hello world<br>
finished!

### analysis

- processes communicate with each other through pipes, a unidirectional data channel.
- dup2() system call can be used to redirect a file descriptor, in this example, STDOUT_FILENO and STDIN_FILENO were used for the write and read ends of the pipe.
