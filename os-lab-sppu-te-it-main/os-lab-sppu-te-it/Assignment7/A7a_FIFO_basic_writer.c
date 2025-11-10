#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main(){
    char *fifo="/tmp/myfifo_demo";
    mkfifo(fifo,0666);
    int fd = open(fifo, O_WRONLY);
    char msg[100];
    printf("Enter message: "); fgets(msg,100,stdin);
    write(fd, msg, sizeof(msg));
    close(fd);
    return 0;
}
