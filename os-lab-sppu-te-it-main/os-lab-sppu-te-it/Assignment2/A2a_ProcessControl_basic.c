#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }
    if (pid == 0) {
        printf("Child: PID=%d PPID=%d\n", getpid(), getppid());
        execlp("echo","echo","Hello from child (via exec)",NULL);
        perror("execlp"); // if exec fails
    } else {
        wait(NULL);
        printf("Parent: child finished, PID=%d\n", pid);
    }
    return 0;
}
