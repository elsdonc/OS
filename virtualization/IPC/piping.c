#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>

int main() {
	int pipefds[2];
	if (pipe(pipefds) == -1) {
		perror("pipe");
		return 1;
	}	
	pid_t pid1 = fork();
	if (pid1 < 0) {
		perror("fork");
		return 1;
	} else if (pid1 == 0) {
		/* close unused read end of pipe */
		close(pipefds[0]);
		dup2(pipefds[1], STDOUT_FILENO);
		close(pipefds[1]);

		printf("hello world\n");
		exit(0);
	}

	pid_t pid2 = fork();
	if (pid2 < 0) {
		perror("fork");
		return 1;
	} else if (pid2 == 0) {
		/* close unused write end of pipe */
		close(pipefds[1]);
		dup2(pipefds[0], STDIN_FILENO);
		close(pipefds[0]);

		char buf[4096];
		memset(buf, 0, sizeof(buf));
		read(STDIN_FILENO, buf, sizeof(buf));
	       	printf("reading from pipe: %s", buf);	
		exit(0);
	}	
	
	for (int i = 0; i < 2; i++) {
		wait(NULL);
	}
	printf("finished!\n");

	return 0;
}
