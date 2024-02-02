#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LONG 2147483647

int main(int argc, char *argv[]) {

    int numOfOne = 0;
    unsigned int mask = 1 << 31;
    unsigned int i;
    char *ptr;
    int value = strtol(argv[1], &ptr, 10);
    if(argc < 2) {
        printf("No command line argument entered, please enter a decimal number or enter -h for help");
    }
    if (strcmp(argv[1], "-h") == 0) {
        printf("Enter an integer value between the values 0-2147483647 to convert it into binary");
        return 0;
    } else if(argc > 2) {
        printf("You can only provide 1 argument, enter -h as the command line argument for help");
    } else if (*ptr != 0 || value > MAX_LONG || value < 0) {
        printf("Not a valid digit, enter -h as the command line argument for help");
        return 0;
    }
    printf("%s", "0b");
    if(value == 0) {
        printf("%s", "0");
    } else {
    for(i = 1; i <= 32; i++) {
        if (value & mask) {
               putchar('1');
               //increment number of ones
               numOfOne++;
            }
            else {
                // checks if there are no 1's already printed don't print 0's 
               if(numOfOne > 0) {
                putchar('0');
               }
            }
        value <<= 1;
    }
    }
    
    return 0;
}