#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

int
main ()
{
    // Sockets are file descriptors
    // Sockets are endpoints for communication
    // There are many types of sockets, the one on this example is a
    // socket IPv4 TCP
    int fd = socket (AF_INET, SOCK_STREAM, 0);

    if (fd == -1)
        {
            perror ("socket");
            return -1;
        }

    printf ("%d\n", fd); // This file descriptor represents an endpoint for
                         // communication, can be passed to
    // future function with sys calls to do things over the network
}
