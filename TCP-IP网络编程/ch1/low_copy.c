#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
void error_handling(char* message);

int main(void)
{
    int fd,ofd;
    char buf[] = "Let's go!\n";

    fd = open("data.txt", O_RDONLY);
    if(fd == -1)
        error_handling("open() fd error!");
    printf("file descriptor: %d \n", fd);

    if(read(fd, buf, sizeof(buf)) == -1)
        error_handling("read() error!");
    printf("file data: %s", buf);

    ofd = open("copy.txt", O_CREAT|O_WRONLY|O_TRUNC);
    if(ofd == -1)
        error_handling("open() ofd error!");
    printf("file descriptor: %d \n", fd);

    if(write(ofd, buf, sizeof(buf)) == -1)
        error_handling("write() error!");
    close(fd);

    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}