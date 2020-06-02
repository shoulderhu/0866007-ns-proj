#include <cstdio>
#include <cstdlib>
#include <curl/curl.h>

#include <fcntl.h>     // open()
#include <unistd.h>

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


    return 0;
}
