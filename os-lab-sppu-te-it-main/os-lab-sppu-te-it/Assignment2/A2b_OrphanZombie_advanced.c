/*
 Demonstrates orphan (child reparented to init) and zombie (child exits, parent sleeps)
 Run twice or observe with `ps -el | grep Z` during sleep.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void zombie_demo() {
    pid_t pid = fork();
    if(pid==0) { // child
        printf("[zombie demo] child pid=%d exiting now\n", getpid());
        exit(0);
    } else if(pid>0) {
        printf("[zombie demo] parent sleeping for 5s (child becomes zombie)\n");
        sleep(5); // during this time child is zombie until parent calls wait
        wait(NULL);
        printf("[zombie demo] parent reaped child\n");
    }
}

void orphan_demo() {
    pid_t pid = fork();
    if(pid==0) {
        printf("[orphan demo] child pid=%d, parent pid=%d. Sleeping 5s then printing new ppid.\n", getpid(), getppid());
        sleep(5);
        printf("[orphan demo] after parent's exit, child's new ppid=%d\n", getppid());
        exit(0);
    } else if(pid>0) {
        printf("[orphan demo] parent exiting immediately (pid=%d)\n", getpid());
        exit(0);
    }
}

int main() {
    int ch;
    printf("1. Zombie demo\n2. Orphan demo\nChoice: ");
    if(scanf("%d",&ch)!=1) return 0;
    if(ch==1) zombie_demo();
    else orphan_demo();
    return 0;
}
