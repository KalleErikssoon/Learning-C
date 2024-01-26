//include input/output header file
#include <stdio.h> 
// include stdlib header file
#include <stdlib.h>
// include string header file for string operations
#include <string.h>
// include ctype header file
#include <ctype.h>
//define ASCII value for the first uppercase character
#define UPPERCASE_START 65
//define ASCII value for the first lowercase character
#define LOWERCASE_START 97
//define ASCII value for the last uppercase character
#define UPPERCASE_END 90
//define ASCII value for the last uppercase character
#define LOWERCASE_END 122

//main function
int main(int argc, char *argv[]) {
    //initialize char array to store user input
    char word[10];
    // initialize int variable with amount of shifts the user requested in the command line argument 
    int numOfShifts = atoi(argv[1]);
    // loop while the input from the user does not equal end of file
    while(!feof(stdin)) {
        printf("%s", "Enter your string\n");
        //read input from user (max 9 char since we need 1 space for the \0)
        scanf("%9s", word);
        // get length of the word array that the user input
        int wordLength = strlen(word);
        //loop for the length of the array entered by user
        for (int i = 0; i < wordLength; i++) {
            //checks if the char at position i is an uppercase letter,
            // and the char int value + the number of shifts the user specified is less than or equal to the last uppercase letter in the ASCII table
            if(isupper(word[i]) && word[i] + numOfShifts <= UPPERCASE_END) {
                // replace char at position i with the character at position i + the number of shifts specified 
                word[i] = word[i] + numOfShifts;
            // checks if the char at position i is an uppercase letter,
            // and the char int value + the number of shifts the user specified is larger than the last uppercase letter in the ASCII table
            } else if (isupper(word[i]) && word[i] + numOfShifts > UPPERCASE_END) { 
                //replace char at position i with char at position i + number of shifts remainder of last uppercase char in ASCII table + the first uppercase char - 1 
                word[i] = ((word[i] + numOfShifts) % UPPERCASE_END) + UPPERCASE_START - 1;
            // checks if the char at position i is a lowercase letter,
            // and the char int value + the number of shifts the user specified is less than the last lowercase letter in the ASCII table
            } else if(islower(word[i]) && word[i] + numOfShifts <= LOWERCASE_END) {
                // replace char at position i with the character at position i + the number of shifts specified
                word[i] = word[i] + numOfShifts;
            // checks if the char at position i is a lowercase letter,
            // and the char int value + the number of shifts the user specified is larger than the last lowercase letter in the ASCII table   
            } else if(islower(word[i]) && word[i] + numOfShifts > LOWERCASE_END) {
                //replace char at position i with char at position i + number of shifts remainder of last lowercase char in ASCII table + the first lowercase char - 1
                word[i] = ((word[i] + numOfShifts) % LOWERCASE_END) + LOWERCASE_START - 1;
            }
        }
        printf("%s\n", word);
        // "reset" the char array
        word[0] = '\0';
    }
    //return 0, indicating succesful execution of the program
    return 0;
}