// A tipical 64-bit linux environment has a memory map that includes:
// Text Segment: Executable code
// Initialized Data Segment: Stores global and static variables
//
// Uninitialized Data Segment (BSS): Hold uninitialized global and static
// variables
//
// Heap: Dynamically allocated memory managed by malloc(), realloc(), and
// free()
//
// Stack: Memory for function call frames, including local variables and return
// addresses
//
// Memory-mapped Regions: Used for shared libraries and files mapped into
// memory
//
// Simplified map:
//
// |-----------------------------|
// | Stack (grows downward)      |
// |-----------------------------|
// | Memory-mapped segments      |
// |-----------------------------|
// | Heap (grows upward)         |
// |-----------------------------|
// | Uninitialized Data (BSS)    |
// |-----------------------------|
// | Initialized Data            |
// |-----------------------------|
// | Text Segment (code)         |
// |-----------------------------|

#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
    int *ptr = (int *)malloc (sizeof (int)); // Request space from the heap
    if (ptr == NULL)
        {
            printf ("Memory allocation failed\n");
            return 1;
        }

    *ptr = 42;
    printf (
        "Value: %d, Address: %p\n", *ptr,
        (void *)ptr); // The (void *) cast makes us get the raw address of ptr
    return 0;
}
