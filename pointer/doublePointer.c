#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **doublePtr;
    int *singlePtr;
    int num = 3;

    singlePtr = &num;
    doublePtr = &singlePtr;

    printf("&num : %p\n", &num);
    printf("singlePtr : %p\n", singlePtr);
    printf("double : %p\n", *doublePtr);
    return 0;
}