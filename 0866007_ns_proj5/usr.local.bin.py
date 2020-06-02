#include <tunables/global>

/usr/local/bin/py {
    #include <abstractions/base>

    deny network,

    /var/Y/*    rw,
}