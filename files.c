#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int
main (int argc, char *argv[])
{
    if (argc != 2)
        {
            printf ("Usage: %s <filename>\n", argv[0]);
            return 0;
        }

    // Flags thend to be bitwise operations, a binary or convines both flags
    // Last parameter are permissions
    int fd = open (argv[1], O_RDWR | O_CREAT, 0644);
    if (fd == -1)
        {
            perror ("open");
            return -1;
        }

    char *mydata = "Hello there file!\n";
    write (fd, mydata, strlen (mydata));
    close (fd);

    return 0;
}
