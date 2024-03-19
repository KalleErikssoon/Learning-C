//credit to geeks for geeks, reference: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// used parts of their example in lines 30-33, and 41-44

#include <stdio.h>      //include stdio header file for input/output
#include <stdlib.h>     // include stdlib header file for standard library functions
#include <string.h>     // include string header file for string operations
void swapChars(char *first, char *second);      // initalize function to swap characters
void permuteInput(char *inputString, int start, int length, char *result, int *index);      //initialize function to permute the user input
int maxPermutations(int strLen);        //initalize function to calculate the max amount of permutations

int main(int argc, char *argv[]) {
    
    if (argc != 2 || strlen(argv[1]) > 10) {        // checks if the amount of arguments does not equal 2, and that the length of the second argument is less than 10
        printf("Invalid input\n");
        return 0;       // return 0, indicating succesful execution of the program
    }

    char *input = argv[1];      //initalize char pointer to the second command line argument
    int length = strlen(input);     //use strlen to calculate the length of the input from user

    int nrOfPermutations = maxPermutations(length);     //set nrOfPermutations to equal the return value of the function maxPermutations
    char *permutations = malloc(nrOfPermutations * (length + 1) + 1);      //initalize char pointer array and allocate memory based on the nr of permutations * (the length of the string + 1) + 1 for null terminator 
    int index = 0; // initalize int variable to keep track of where to append the next permutation
    permuteInput(input, 0, length - 1, permutations, &index);       //call the permuteInput function with the user input, start (0), length of string - 1, permutations and index
    printf("All permutations of the string %s are: %s\n", input, permutations);
    free(permutations); // Free allocated memory
    return 0;       // return 0, indicating succesful execution of the program
}

void swapChars(char *first, char *second) {     //implementation of function for swapping characters
    char temp = *first;     //set value of temp char to the first char pointer
    *first = *second;       //set value of first char pointer to second char pointer
    *second = temp;         //set value of second char pointer to temp value
}

void permuteInput(char *inputString, int start, int length, char *result, int *index) { //implementation of function to permute the user input
    if (start == length) {      //checks if the start int parameter equals the length parameter
        sprintf(result + *index, "%s ", inputString);       //function for writing the inputString to the result with a space in between
        *index += strlen(inputString) + 1; // increment the current index/position in permutations + 1 for the space 
    } else {        //else 
        for (int i = start; i <= length; i++) {     //for loop going over the start to length parameters
            swapChars((inputString + start), (inputString+i));      //call swapChars function to swap characters
            permuteInput(inputString, start +1, length, result, index);     //recursively call the permuteInput function 
            swapChars((inputString + start), (inputString + i)); // swap back the characters
        }
    }
}
int maxPermutations(int strLen) {       //implementation of function for calculating the max amount of permutations based on the input string
    int maxNum = 1;     //initialize maxNumber integer variable to 1
    for(int i = strLen; i > 0; i--) {       // loop over the length of the parameter down to 1
        maxNum *= i;        //multiply the maxNum by i each iteration
    }
    return maxNum;      //return the max number variable
}