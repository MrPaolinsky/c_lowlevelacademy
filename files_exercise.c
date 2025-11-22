#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void
print_the_flag ()
{
    FILE *fp = fopen ("/tmp/flag", "r");
    if (fp == NULL)
        {
            perror ("fopen");
        }

    char buffer[255]; // Right thing would be checking the actual size of the
                      // file

    int ret_size = fread (buffer, sizeof (*buffer), sizeof (buffer), fp);

    printf (buffer); // Possibly unsafe
    printf ("\n");
    fclose (fp);
}

int
main (int argc, char *argv[])
{
    print_the_flag ();
    return EXIT_SUCCESS;
}
