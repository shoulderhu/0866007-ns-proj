#include <tunables/global>

/var/Y/py {
    #include <abstractions/base>

    deny network,

    /var/Y/*    mrw,
}