// include input/output header file
#include <stdio.h>
// include stdlib header file
#include <stdlib.h>
//defines MAX_number
#define MAX_NUMBER 10
// main function
int main() {
    //initialize int variables for the actual number psuedorandomly generated and the user guessed number 
    int actualNum, guessedNum = 45, userChoice = 1;
    //generate psuedorandom number
    actualNum = 1 + rand() % 100; 
    //initialize variable storing the number of guesses so far by the user to 0
    int numOfGuesses = 0;
    printf("Guess a number between 1-100: \n");
    //scan first guessed number by user and store it in variable guessedNum
    scanf("%d", &guessedNum);
    //increment the number of guesses made by the user by 1
    ++numOfGuesses;
    //while loop that keeps going as long as the number of guesses is less than the max number of guesses
    while(numOfGuesses <= MAX_NUMBER) {
         // Check if the user has reached the maximum number of guesses
        if(numOfGuesses == MAX_NUMBER) {
            printf("You've reached the maximum number of guesses.\n");
            printf("If you want to play again press 0, to exit enter anything else\n");
            scanf("%d", &userChoice);
            //generate new psuedorandom number
            actualNum = 1 + rand() % 100; 
            //set number of guesses to 0
            numOfGuesses = 0;
            printf("Guess a number between 1-100: \n");
            //scan the new number guessed by the user
            scanf("%d", &guessedNum);
            //increment number of guesses by 1
            ++numOfGuesses;
            // checks if user inputs anything other than 0
        }
        //checks if guessed number is less than actual number
        else if(guessedNum < actualNum) {
            printf("Your guess is too low, guess again \n");
            //scan the new number guessed by the user
            scanf("%d", &guessedNum);
            //increment the number of guesses by 1 
            ++numOfGuesses;
        //checks if the number guessed is higher than the actual number
        } else if (guessedNum > actualNum) {
            printf("Your guess is too high, guess again \n");
            //scan the new number guessed by the user
            scanf("%d", &guessedNum);
            //increment the number of guesses by 1
            ++numOfGuesses;
        //checks if the guessed number is the same as the actual number
        } else if(guessedNum == actualNum) {
            printf("You guessed %d times and your guess is correct\n", numOfGuesses);
            printf("%s", "If you want to play again press 0, if you like to exit enter anything else\n");
            //scan the user choice
            scanf("%d", &userChoice);
            //checks if user chose 0
            if(userChoice == 0) {
                //generate new psuedorandom number
                actualNum = 1 + rand() % 100; 
                //set number of guesses to 0
                numOfGuesses = 0;
                printf("Guess a number between 1-100: \n");
                //scan the new number guessed by the user
                scanf("%d", &guessedNum);
                //increment number of guesses by 1
                ++numOfGuesses;
            // checks if user inputs anything other than 0
            } else {
                //return 0, indicating succesful execution of program
                return 0;
            }
        }
    }
    //return 0, indicating succesful execution of program
    return 0;
}