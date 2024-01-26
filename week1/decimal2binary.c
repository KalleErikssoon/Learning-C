//include input/output header file
#include <stdio.h> 
// include stdlib header file to use function atoi to check if the input is a valid integer
#include <stdlib.h>

// main function
int main(int argc, char *argv[]) {
    //initialize counters to 0 for number of ones and zeros
    int numOfZero = 0, numOfOne = 0;
    // checks if no argument is provided (other than file name)
    if(argc < 2) {
        printf("%s", "Error: No number provided. Please provide a number as a command line argument.");
        //return 0, indicating succesful execution of program
        return 0;
    }
    // initialize the number entered by user in command line, uses atoi function to make the char value into int
    //if the value is not a number the atoi function will return 0
    int chosenNum = atoi(argv[1]);
    // initialize mask variable, left shift by 31 bits
    unsigned int mask = 1 << 31;
    
    // if chosenNum is equal to 0 (if something other than int is put as command line argument)
    if (chosenNum == 0) {
        printf("%s", "Error: Invalid number.");
    // if the user input a valid number enter the else block
    } else {
        printf("Number: %d\n", chosenNum);
        printf("Binary: 0b");
        // loop 32 times (max number of bits in an integer value)
        for(unsigned int i = 1; i <= 32; i++) {
        // checks if the chosen number and mask are set
        if (chosenNum & mask) {
               printf("%s", "1");
               //increment number of ones
               numOfOne++;
            }
            // else the chosen num and mask are not set
            else {
                // checks if there any bits are already set 
               if(numOfOne > 0) {
                printf("%s", "0");
                //increment number of zero's
                numOfZero++;
               }
            }
            // left shift chosenNum by 1 bit towards the mask
            chosenNum <<= 1;
        }
        printf("\nNumber of 0s: %d\nNumber of 1s: %d\n", numOfZero, numOfOne);
    }
    //return 0, indicating succesful execution of the program
    return 0;
}
