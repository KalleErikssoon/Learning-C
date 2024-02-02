//initialize void method to calculate and print
void calcAndPrint(int *binary);
//include input/output header file
#include <stdio.h>
//include stdlib file
#include <stdlib.h>
//main function
int main(int argc, char *argv[]) {
    
    //initialize char pointer 
    char *ptr;
    //initialize int array to store binary values
    int binary[8];
    //checks if there is too many/too few arguments 
    if (argc != 6) {
        printf("Invalid input, needs 5 arguments");
        //return 0, indicating succesful execution of the program
        return 0;
    }
    // use strtol function to get int value of first argument
    int value = strtol(argv[1], &ptr, 10);
    // checks if the value is larger than 1, less than 0, or if a part of the argument is not a number (in which case it is stored as ASCII value in the pointer)
    if(value > 1 || *ptr != 0 || value < 0) {
        printf("Invalid input, needs to be the integer value 0 or 1");
        //return 0, indicating succesful execution of the program
        return 0;
    } else {
        //set the first binary value to what the first argument was as integer
        binary[0] = value;       
    }
    //// use strtol function to get int value of first argument
    value = strtol(argv[2], &ptr, 10);
    // checks if the value is larger than 4, less than 0, or if a part of the argument is not a number (in which case it is stored as ASCII value in the pointer)
    if(value > 4 || *ptr != 0 || value < 0) {
        printf("Invalid input, needs to be an integer value between 0-4");
        //return 0, indicating succesful execution of the program
        return 0;
    } else {
        // initialize unsigned int mask and left shift 2 bits
        unsigned int mask = 1 << 2;
        // loop over the length of this part of the bit (always 3 bits)
        for(int i = 1; i < 4; i++) {
            // checks if the value & mask are true
            if (value & mask) {
                // set value at position i in array to 1
                binary[i] = 1;
            }
            else {
                // set value at position i in array to 0
                binary[i] = 0;
            }
        // right shift the mask by 1 bit 
        mask >>= 1;
        }
    }
    // use strtol function to get int value of first argument
    value = strtol(argv[3], &ptr, 10);
    // checks if the value is larger than 2, less than 0, or if a part of the argument is not a number (in which case it is stored as ASCII value in the pointer)
    if(value > 2 || *ptr != 0 || value < 0) {
        printf("Invalid input, needs to be the integer value between 0-2");
        //return 0, indicating succesful execution of the program
        return 0;
    } else {
        // initialize unsigned int mask and left shift 1 bit
        unsigned int mask = 1 << 1;
         // loop over the length of this part of the bit (always 2 bits)
        for(int i = 4; i < 7; i++) {
            // checks if the value & mask are true
            if (value & mask) {
                // set value at position i in array to 1
                binary[i] = 1;
            }
            else {
                // set value at position i in array to 0
                binary[i] = 0;
            }
        // right shift the mask by 1 bit     
        mask >>= 1;
        }
    }
    // use strtol function to get int value of 4th argument
    value = strtol(argv[4], &ptr, 10);
    // checks if the value is larger than 1, less than 0, or if a part of the argument is not a number (in which case it is stored as ASCII value in the pointer)
    if(value > 1 || *ptr != 0 || value < 0) {
        printf("Invalid input, needs to be the integer value between 0-1");
        //return 0, indicating succesful execution of the program
        return 0;
    } else {
        //set the 6th binary value to what the 4th argument was as integer
        binary[6] = value; 
    }
    // use strtol function to get int value of 5th argument
    value = strtol(argv[5], &ptr, 10);
    // checks if the value is larger than 1, less than 0, or if a part of the argument is not a number (in which case it is stored as ASCII value in the pointer)
    if(value > 1 || *ptr != 0 || value < 0) {
        printf("Invalid input, needs to be the integer value between 0-1");
        //return 0, indicating succesful execution of the program
        return 0;
    } else {
        //set the 7th binary value to what the 5th argument was as integer
        binary[7] = value; 
    }
    for(int i = 0; i < 8; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
    // call function to calculate and print binary representation of the int values
    calcAndPrint(binary);
}
// implementation of calculate and print method, takes pointer to int array for storing binary nums, converts to int and prints it as hexadecimal
void calcAndPrint(int *binary) {
    // initialize decimal variable that stores the converted binary number as decimal
    int decimal = 0;
    // loop for the length of the passed array
    for (int i = 0; i < 8; i++) {
        // left shift bits of decimal varible by 1 (won't do anything first iteration)
        decimal <<= 1;
        // checks if the current character in array equals 1
        if (binary[i] == 1) {
            //compare bit of decimal to corresponding bit of 1
            decimal |= 1;
        // checks if current character in array equals 0
        } else if (binary[i] != 1) {
            //do nothing
           ;
        }
    }
    printf("Hexadecimal value: %X\n", decimal);
}