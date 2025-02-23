### program functionality
1. main takes number of loops as an argument
2. prints initial value of the counter 
3. 2 threads are created with a worker function that increments a global counter loops amount of times
4. after threads have finished executing the worker function, the final value of counter is printed

### compile instructions
```
gcc threads.c
```

### run instructions
```
./a.out <numLoops> 
``` 

### expected results
```
./a.out 1000
```
Initial value: 0<br>
Final value: 2000

### actual results
- For small loop values, the expected final value of count is 2*numLoops.
- For larger loop values like 100000, the final value will result in different values each time.

### analysis
- The reason that larger loop values return incorrect final values is because increment operations don't happen atomically (all at once), allowing race conditions to occur.
- There are 3 steps to increment the counter:
	1. Load value from memory into register
	2. Increment value
	3. Store value back into memory
- A race condition occurs when multiple threads try to access the same resource at the same time.
- The reason that small loop values return correct final values every time is because of CPU scheduling. A thread will finish executing the worker function faster with smaller loop values, eliminating race conditions.
