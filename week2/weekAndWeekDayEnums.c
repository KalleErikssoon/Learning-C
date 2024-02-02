// include header file for input/output
#include <stdio.h>
// include header file for boolean values
#include <stdbool.h>
//include header file for sleep method 
#include <unistd.h>

//initialize void method to clear buffer
void clearBuffer();

//initialize enums for each day of the week
enum daysInWeek {Mon = 1, Tue, Wed, Thur, Fri, Sat, Sun};
//initialize enums for each week
enum weeks {week1 = 1, week2, week3, week4, week5};
// main function
int main() {
    //initialize boolean variable to false for checking if the input is valid by user
    bool validInput = false;
    // initialize int variable to store the user chosen week
    int week, chosenDay;
    // initialize char array to store the user chosen day of the week
    char userInput[32];
    // initialize enum variable for day in the week
    enum daysInWeek day;
    // initialize enum variable for the chosen week
    enum weeks chosenWeek;
    // intialize array of pointers to strings
    const char *weekDay[] = {"", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat", "Sun"};
    printf("%s", "Provide starting week: ");
    // scan user input for chosen day
    scanf("%d", &week);
    // call clear buffer method
    clearBuffer();
    printf("%s", "Provide starting day: ");
    scanf("%d", &chosenDay);
    // check if the user input is > 5 or < 1
    if(week > week5 || week < week1) {
        printf("Invalid week");
        //return 0, indicating succesful execution of the program
        return 0;
        // else week is valid
    } else {
        //set the enum variable to the user choice
        chosenWeek = week;
        //set valid input to true
        validInput = true;
    }
    // checks if the chosen day is more than 7 or less than 1 
    if(chosenDay > Sun || chosenDay < Mon) {
        printf("Invalid day");
        // return 0, indicating succesful execution of the program
        return 0;
        // else day is valid
    } else {
        // set the enum variable day to the user input
        day = chosenDay;
        // set boolean variable to true
        validInput = true;
    }
    // checks if the user has input an invalid day
    if (!validInput) {
        printf("Invalid day");
        //else input is valid
    } else {
        // loop over the weeks from the user chosen week to last week
        for (int i = chosenWeek; i <= week5; i++) {
            // set chosenWeek to what i currently is
            chosenWeek = i;
            // loop over each day of the week from the day the user chose to last day of week 
            for(int j = day; j <= Sun; j++) {
                // checks if the day is equal to 4th day or 2nd day, then print the day with the substring "sday" at the end of the week day
                if(j == 4 || j == 2) {
                    printf("Week %d, %ssday\n", chosenWeek, weekDay[j]);    
                // checks if the day is equal to the 3d day, then print with the substring "nesday" at the end of the week day
                } else if(j == 3) {
                    printf("Week %d, %snesday\n", chosenWeek, weekDay[j]);
                //checks if the day is equal to the 6th day, then print with the substring "urday" at the end of the week day
                } else if(j == 6) {
                    printf("Week %d, %surday\n", chosenWeek, weekDay[j]);
                // else print with the substring "day" at the end of the week day
                } else {
                printf("Week %d, %sday\n", chosenWeek, weekDay[j]);
                }
                //sleep the thread for 1 second
                sleep(1);
            }
            // set day to 1 (first day)
            day = 1;
        }
    }
}

//method to clear buffer
void clearBuffer() {
    // get the next char while it does not equal end of line (\n) and it does not equal end of file
    while(getchar() != '\n' && getchar() != EOF) {
        // do nothing
        ;
    }
}