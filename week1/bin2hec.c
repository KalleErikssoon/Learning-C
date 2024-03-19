#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//void method to convert binary to decimal, then print in hex
void calcAndPrint(char *binary);

//main function
int main(int argc, char *argv[]) {
    //char array to store the input from the terminal
    char numFromDec[34] = {0};
    //variable to store char input and i to increment place in above array 
    int charInput, i = 0;
    //checks if there is only program as cmd line argument
    if (argc < 2) {
        //checks if there is something in the terminal currently
        if (!isatty(0)) {
            //while the terminal does not have new line/EOF/is less than max binary length
            while ((charInput = getchar()) != '\n' && charInput != EOF && i < 34) {
                //increment position in char array and put the input from getchar in the array
                numFromDec[i] = charInput;
                i++;
            }
            //null-terminate the char array
            numFromDec[i] = '\0';
            //call calculate and print method with the array filled above as argument
            calcAndPrint(numFromDec);
        // if there is nothing in the terminal print that no command line argument was provided            
        } else {
            printf("No command line argument provided\n");
            // return 0, indicating succesful execution of the program
            return 0;
        }
    //checks if the user input the characters -h
    } else if (strcmp(argv[1], "-h") == 0) {
        printf("Enter a binary number (e.g., 1010) to convert it into hexadecimal\n");
        // return 0, indicating succesful execution of the program
        return 0;
    // check if there is more than 2 cmd line arguments provided
    } else if (argc > 2) {
        printf("You can only provide 1 argument, enter -h as the command line argument for help\n");
    } else {
        // call calculate and print method with command line argument as parameter
        calcAndPrint(argv[1]);
    }
    // return 0, indicating succesful execution of the program
    return 0;
}

//implementation of the method initialized at top of program
void calcAndPrint(char *binary) {
    // initialize variable that stores the length of the passed array as an integer 
    int length = strlen(binary);
    // initialize decimal variable that stores the converted binary number as decimal
    int decimal = 0;
    // loop for the length of the passed array
    for (int i = 0; i < length; i++) {
        // left shift bits of decimal varible by 1 (won't do anything first iteration)
        decimal <<= 1;
        printf("iteration: %d decimal: %d\n", i, decimal);
        // checks if the current character in array equals 1
        if (binary[i] == '1') {
            //compare bit of decimal to corresponding bit of 1
            decimal |= 1;
            printf("inside if iteration: %d decimal: %d\n", i, decimal);
        // checks if current character in array equals 0
        } else if (binary[i] != '0') {
            //do nothing
           ;
        }
    }
    printf("Hexadecimal value: 0X%X\n", decimal);
}
