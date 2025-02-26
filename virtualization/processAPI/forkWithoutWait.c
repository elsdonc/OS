#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv) {
	pid_t pid = fork();
	if (pid < 0) {
		perror("fork");
		return 1;
	} else if (pid == 0) {
		printf("(pid: %d) - child\n", (int) getpid());
	} else {
		printf("(pid: %d) - parent of %d\n", (int) getpid(), pid);	
	}
	return 0;
}
