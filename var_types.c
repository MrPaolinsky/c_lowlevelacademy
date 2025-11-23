#include <stdio.h>

int
main (int argc, char *argv[])
{
    // int x;
    //
    // char y;          // 1 byte
    // short s;         // 2 byte
    // int i;           // 4 byte, 32 bits by default
    // long long int l; // 8 byte, 64 bits
    //
    // // All of these can be unsigned
    // unsigned int xx
    //     = -3; // This will give a compiler warning, but it does compile
    //
    // // First bit tells us if a value is signed or not, if it is unsigend
    // // that bit can be used to store extra information.
    //
    // float pi = 3.14;      // Not acurate
    // double pi2 = 3.14159; // Extra acuracy, double storage
    //
    // // Most types are just aliases

    // TYPE CASTING
    unsigned int x = 4;

    // Something happens, and we want to sign x
    int sx = (int)(x);
    // This is interesting, we are converting two types with the same size

    unsigned int bigx = 0xfffffefe; // Close to size limit
    short kindabig = (short)(bigx);
    // This converts a 32bits type into a 16 one. The compiler allows this, but
    // warns us. There will be information loss "downcast"

    short short2 = -1;
    int wasashort = (int)(short2); // Upcast
    // 16 bits to 32 bits, here a signed extension will happen.

    float f = 4.12;
    int wasafloat = (int)(f); // assembly call under the hood will round the
                              // original float to nearest integer.

    // Pointers can be casted as well
}
