#include <cstdio>
#include <unistd.h>
#include <fcntl.h>       // open()
#include <sys/socket.h>  // socket()

int main() {
    int fd;

    if ((fd = open("/var/X/test.txt", O_RDWR)) == -1) {
        perror("/var/X/test.txt");
    } else {
        close(fd);
    }

    if ((fd = open("/var/Y/test.txt", O_RDWR)) == -1) {
        perror("/var/Y/test.txt");
    } else {
        close(fd);
    }

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket()");
    } else {
        close(fd);
    }

    return 0;
}
