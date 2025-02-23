### program functionality
1. creates a file /tmp/file
2. writes data into the file
3. closes the file

### compile instructions
```
gcc io.c
```

### run instructions
```
./a.out
```

### expected results
- there will be a file /tmp/file containing the string "hello world"
```
cat /tmp/file
```
hello world

### analysis
- open(), write(), close() system calls are routed to a part of the OS called the file system which is the software that manages disk storage.
- Most file systems delay writes for performance reasons to potentially batch them into larger groups.
- There are write protocols such as journaling or copy-on-write, to handle problems of system crashes during writes.
