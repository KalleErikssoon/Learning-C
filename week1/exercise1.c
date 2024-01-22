#include <stdio.h>

//main function
int main(int argc, char *argsv[]) {

    //variable to store the user selected number
    int selectedNum = 1;
    printf("%s", "Select a number: \n");
    //scan user input and store it in selectedNum variable
    scanf("%d", &selectedNum);

    //while loop that keeps going until the users chooses a number that isn't between 1-5
    while (selectedNum > 0 && selectedNum < 6) {
        //if the selected number is 1 print
        if(selectedNum == 1) {
            printf("%s", "One selected, select a new number or enter any number other than 1-5 to exit\n");
            //scan user input and store it in selectedNum variable
            scanf("%d", &selectedNum);
        //if the selected number is 2 print
        } else if (selectedNum == 2) {
            printf("%s", "Two selected select a new number or enter any number other than 1-5 to exit\n");
            //scan user input and store it in selectedNum variable
            scanf("%d", &selectedNum);
         //if the selected number is 3 print
        } else if (selectedNum == 3) {
            printf("%s", "Three selected select a new number or enter any number other than 1-5 to exit\n");
            //scan user input and store it in selectedNum variable
            scanf("%d", &selectedNum);
        //if the selected number is 4 print
        } else if (selectedNum == 4) {
            printf("%s", "Four selected select a new number or enter any number other than 1-5 to exit\n");
            //scan user input and store it in selectedNum variable
            scanf("%d", &selectedNum);
         //if the selected number is 5 print    
        } else if(selectedNum == 5) {
            printf("%s", "Five selected select a new number or enter any number other than 1-5 to exit\n");
            //scan user input and store it in selectedNum variable
            scanf("%d", &selectedNum);
            // if anything other than a number between 1-5 is selected return 0, indicating succesful execution of the program
        } else {
            //return 0, indicating succesful execution of the program
            return 0;
        }
    }
    ////return 0, indicating succesful execution of the program
    return 0;
}
/*
Write a program that reads in an integer number between 1 and 5 from the keyboard and prints out one of
existing five sentences on the console depending on what number was entered. You can invent the sentences
as you want, but each sentence should be unique.
The program continues to ask for a new number and exits if number isn ́t in the interval 1 to 5.
*/