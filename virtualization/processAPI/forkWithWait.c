#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv) {
	pid_t pid = fork();
	if (pid < 0) {
		perror("fork");
		return 1;
	} else if (pid == 0) {
		printf("(pid: %d) - child\n", (int) getpid());
	} else {
		int status;
		if (wait(&status) == -1) {
			perror("wait");
			return 1;
		}
		if (WIFEXITED(status)) {
			printf("child terminated normally\n");
		} else {
			printf("child terminated abnormally\n");
		}
		printf("(pid: %d) - parent of %d\n", (int) getpid(), pid);	
	}
	return 0;
}
