#include <stdbool.h>
#include <stdio.h>

struct employee_t
{
    int id;
    int income;
    bool staff;
};

void
initialize_employee (struct employee_t *e)
{
    e->id = 0;
    e->income = 0;
    e->staff = false;
    return;
}

void
swap (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int
main ()
{
    int x = 3;
    int *pX = &x; // A pointer stores the raw address of another variable
                  // & means "the address of"

    // * dereferences pointers "Gets value of pointed address"
    printf ("%d\n", *pX);
    printf ("%p\n", pX);

    struct employee_t bob;
    initialize_employee (&bob);
    printf ("%d\n", bob.income);

    int a = 10;
    int b = 20;
    int *pA = &a;
    int *pB = &b;

    printf ("%d, %d\n", *pA, *pB);
    swap (pA, pB);
    printf ("%d, %d\n", *pA, *pB);

    return 0;
}
