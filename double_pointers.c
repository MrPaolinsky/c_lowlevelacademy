#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    STATUS_GOOD,
    STATUS_BAD,
} status_t;

status_t
foo (int **data, int len)
{
    int *temp = NULL;
    temp = realloc (*data, len);

    if (temp == NULL)
        {
            *data = NULL;
            return STATUS_BAD;
        }

    *data = temp;
    return STATUS_GOOD;
}

int
challenge (int **ptr)
{
    int value = 10;
    *ptr = (int *)malloc (sizeof (int));

    if (ptr == NULL)
        {
            fprintf (stderr, "Memory allocation failed \n");
            return -1;
        }

    **ptr = value;
    return 0;
}

int
main ()
{
    int *first = malloc (64);
    if (STATUS_BAD == foo (&first, 128))
        {
            printf ("Ugh \n");
        }

    int *challengeNumber = malloc (sizeof (int));
    challenge (&challengeNumber);
    printf ("%d\n", *challengeNumber);

    free (challengeNumber);
    challengeNumber = NULL;
    free (first);
    first = NULL;

    return 0;
}
