#include <stdio.h>
#include <string.h>

/**
 * Illustrates, how to define, assign and reference a pointer.
 */
void simplePointer()
{
    printf("- %s, %d\n", __FUNCTION__, __LINE__);
    
    int a = 16;
    int b = 32;
    int c = 48;
    int *numPtr = 0;

    printf("numPtr points to adress %p\n", numPtr);

    numPtr = &a;
    printf("numPtr points to adress %p - value %d\n", numPtr, *numPtr);

    numPtr = &b;
    printf("numPtr points to adress %p - value %d\n", numPtr, *numPtr);

    numPtr = &c;
    printf("numPtr points to adress %p - value %d\n", numPtr, *numPtr);
}

/**
 * Illustrate example from slides - pointer to char.
 */
void simplePointerWithChar()
{
    printf("- %s, %d\n", __FUNCTION__, __LINE__);

    char a = 16;
    char *numPtr = 0;

    numPtr = &a;
    printf("numPtr points to adress %p - value %d\n", numPtr, *numPtr);

    // numPtr++; // This points numPtr to the next memory element ... whatever this means ...
    // printf("numPtr points to adress %p - value %d\n", numPtr, *numPtr);
}

/**
 * Do some pointer arithmetics.
 * Stepwise increase one pointer and see what happens to its address and the dereferenced value.
 */
void pointerUsage()
{
    printf("- %s, %d\n", __FUNCTION__, __LINE__);

    int MAX_ELEM = 10;

    // Define some array of ints and fill it
    int numbs[MAX_ELEM];
    for (int i = 0; i < MAX_ELEM; i++)
    {
        numbs[i] = i * i;
    }

    // this pointer will keep track on our position
    int *pos;

    // Set to first element
    pos = numbs;

    printf("numbs points to adress %p - value %d\n", numbs, *numbs);
    printf("pos points to adress %p - value %d\n", pos, *pos);

    // Stepwise, manually increment pointer
    pos++;
    printf("pos points to adress %p - value %d\n", pos, *pos);
    pos++;
    printf("pos points to adress %p - value %d\n", pos, *pos);
    pos++;
    printf("pos points to adress %p - value %d\n", pos, *pos);
    pos++;
    printf("pos points to adress %p - value %d\n", pos, *pos);
}

/**
 * Pointer arithmetics shown by diagonally iterating through a two-dimensional array.
 */
void pointerArithmeticsMultiDim()
{
    printf("- %s, %d\n", __FUNCTION__, __LINE__);

    // Define and fill the array
    int maxElem = 15;
    int x[maxElem][maxElem];

    for (int i = 0; i < maxElem; i++)
    {
        for (int j = 0; j < maxElem; j++)
        {
            x[i][j] = i + j * j;
        }
    }

    // "Debug" Output
    for (int i = 0; i < maxElem; i++)
    {
        for (int j = 0; j < maxElem; j++)
        {
            printf("%3.1d ", x[i][j]);
        }
        printf("\n");
    }

    printf("    x   points to adress %p - value %d\n", x, x[0][0]);
    // Iterate with pointer over diagonal elements
    for (int i = 0; i < maxElem; i++)
    {
        // Calculate the position
        //        -------------v start ----v row -----v column
        int *pos = (int *)(&x[0][0] + (i * maxElem) + i);
        printf("%d - pos points to adress %p - value %d\n", i, pos, *pos);
    }
}

/**
 * An own implementation of the size_t strlen ( const char * str ) function.
 * @return Length of param str .
 */
int myOwnStrleng(const char *s)
{
    const char *p = s;
    while (*p != '\0')
        p++;

    // p-s gives the number of chars we iterated over
    return p - s;
}
/**
 * Calls the function myOwnStrleng(const char *s)
 */
void stringMagic()
{
    printf("- %s, %d\n", __FUNCTION__, __LINE__);

    const char *str01 = "Hello World!";
    printf("The length of str \"%s\" is: %d\n", str01, myOwnStrleng(str01));
    const char *str02 = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr";
    printf("The length of str \"%s\" is: %d\n", str02, myOwnStrleng(str02));
}

#include <stdlib.h>
/**
 * Function to intentionally create a memory leak.
 * Check with valgrind (https://valgrind.org/)!
 */
void memoryLeaker()
{
    printf("- %s, %d\n", __FUNCTION__, __LINE__);

    char *str01;
    for (int i = 0; i < 10; i++)
    {
        // We reserve some memory for our string ...
        str01 = (char *)malloc(25 * sizeof(char));
        sprintf(str01, "Some text - %d\n", i);
        printf("%s", str01);
    }

    //... but we free it only once.
    free(str01);
}

/**
 * Solution suggestion for the excercise for memory management.
 */
void uebung_SpeicherverwaltungInC()
{
    printf("- %s, %d\n", __FUNCTION__, __LINE__);

    int *anotherPtr;
    int *iPtr = (int *)malloc(5 * sizeof(int));
    *iPtr++ = 10;
    *iPtr++ = 11;
    *iPtr++ = 12;
    *iPtr++ = 13;
    *iPtr = 14;

    for (anotherPtr = iPtr; iPtr - anotherPtr < 5; anotherPtr--)
    {
        printf("Current value: %d\n", *anotherPtr);
    }
}

int main()
{
    simplePointer();
    simplePointerWithChar();
    pointerUsage();
    pointerArithmeticsMultiDim();
    stringMagic();
    memoryLeaker();
    uebung_SpeicherverwaltungInC();

    return 0;
}