/*
 Simple shared memory example using POSIX shm_open.
 Compile with -lrt if needed (some systems).
*/
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h>           
#include <unistd.h>
#include <string.h>

int main(){
    const char *name = "/myshm_demo";
    const int SIZE = 4096;
    int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);
    void *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    char msg[100];
    printf("Enter message to write to shared memory: ");
    fgets(msg,100,stdin);
    sprintf(ptr, "%s", msg);
    printf("Written. Now reading back: %s\n", (char*)ptr);
    munmap(ptr, SIZE);
    close(shm_fd);
    // Note: to remove shm object use shm_unlink(name) when appropriate
    return 0;
}
