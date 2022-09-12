/**
 * C program to rotate bits of a number.
 * 		https://codeforwin.org/2017/12/c-program-rotate-number-bits.html (fuente del código)
 * 		https://stackoverflow.com/questions/2835469/how-to-perform-rotate-shift-in-c
 * 		https://en.wikipedia.org/wiki/Bitwise_operations_in_C#Shift_operators
 * 		https://en.wikipedia.org/wiki/Bitwise_operation#Circular_shifts
 */

// De https://www.i-programmer.info/programming/cc/12619-fundamental-c-shifts-and-rotates.html?start=1
// 
// It is said that most compilers will detect the above idioms and convert the instructions into a machine code rotate instruction if possible.
// GCC does this optimization, but only if you make sure that the rotation is positive. That is:
// 
// unsigned int data=0x0F;
// data= data>> (unsigned) 1 | data<< (unsigned)31;
// 
// compiles to ASM:
// 
// ror  %eax


#include <stdio.h>

#define INT_SIZE sizeof(int)        // Size of int in bytes
#define INT_BITS INT_SIZE * 8 - 1   // Size of int in bits - 1


/* Function declarations */
int rotateLeft(int num, unsigned int rotation);
int rotateRight(int num, unsigned int rotation);


int main()
{
    int num;
    unsigned int rotation;

    /* Input number from user */
    printf("Ingrese un numero: ");
    scanf("%d", &num);

    /* Input number of rotation */
    printf("Cuanto lo quiere rotar? ");
    scanf("%u", &rotation);


    /* Print rotated number */
    printf("%d rotado %u veces a la izquierda = %d\n\n",  num, rotation, rotateLeft(num, rotation));
    printf("%d rotado %u veces a la derecha = %d\n", num, rotation, rotateRight(num, rotation));


    return 0;
}



/**
 * Function to rotate bits of a number to left.
 *
 * @num         Number to rotate.
 * @rotation    Number of times to rotate left.
 */
int rotateLeft(int num, unsigned int rotation)
{
    int DROPPED_MSB;

    // The effective rotation
    rotation %= INT_BITS;


    // Loop till rotation becomes 0
    while(rotation--)
    {
        // Get MSB of num before it gets dropped
        DROPPED_MSB = (num >> INT_BITS) & 1; 

        // Left rotate num by 1 and 
        // Set its dropped MSB as new LSB
        num = (num << 1) | DROPPED_MSB;
    }

    return num;
}



/**
 * Function to rotate bits of a number to right.
 *
 * @num         Number to rotate.
 * @rotation    Number of times to rotate right.
 */
int rotateRight(int num, unsigned int rotation)
{
    int DROPPED_LSB;

    // The effective rotation
    rotation %= INT_BITS;


    // Loop till rotation becomes 0
    while(rotation--)
    {
        // Get LSB of num before it gets dropped
        DROPPED_LSB = num & 1;

        // Right shift num by 1 and 
        // Clear its MSB
        num = (num >> 1) & (~(1 << INT_BITS));

        // Set its dropped LSB as new MSB
        num = num | (DROPPED_LSB << INT_BITS);
    }

    return num;
}
