/*
Write a program that creates an array of integers, array[MAX], and then fill it with MAX number of random
integers from 1 to 99. Let then the program prints out the following:
The value of the address of the array (pointer) is: xxxxxxxxxx
First integer in the array is (array[0]): xxxxxxxxxx
The last integer in the array is: xxxxxxxxxx
The size of an integer (number of bytes) is: xxxxxxxxx
The size of the whole array in bytes is: xxxxxxxxx
The program shall then, by use of a pointer, print out each integer value and then print the value multiplied by
two.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 10

void generateNumbers(int *arr);

int main() {
    srand(time(0));
    int array[MAX];
    generateNumbers(array);
    printf("The value of the address of the array (pointer) is: %p\n", &array);
    printf("First integer in the array is (array[0]): %d\n", array[0]);
    printf("The last integer in the array is: %d\n", array[9]);
    printf("he size of an integer (number of bytes) is: %d\n", sizeof(int));
    printf("The size of the whole array in bytes is: %d\n", sizeof(array));
    int *ptr = array;
    for(int i = 0; i < MAX; i++) {
        printf("Value at position %d is: %d\n", i, *ptr);
        printf("Value at position %d multiplied by 2 is: %d\n", i, *ptr * 2);
        ptr++;
    }
    return 0;
}

void generateNumbers(int *arr) {
    int num = 0;
    for (int i = 0; i < MAX; i++) {
        num =  rand() % 100 + 1;
        arr[i] = num;
    }
}
