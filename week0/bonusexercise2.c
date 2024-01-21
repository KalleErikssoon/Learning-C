//include output/input header file
#include <stdio.h>
// include string header file for string operations
#include <string.h>

//main function of the program, takes amount of command line argument(s) as first parameter as an integer, 
// and the actual command line arguments as second parameter as an array
int main(int argc, char* argv[]) {

    //checks if there is no command line argument (except for file name)
    if(argc == 1) {
        printf("No command line argument provided, please provide a name.");
        //returns 0 if condition is met after printing, indicating the program executed succesfully
        return 0;
    }
    
    // Use strlen method to check the length of the second command line argument
    int length = strlen(argv[1]);
    // Checks if length of string entered is less than 3 characters
    if(length < 3) {
        printf("Name too short, min 3 characters");
    // checks if length of string entered is more than 50 characters
    } else if (length > 50) {
        printf("Name too long, max 50 characters");
    // if the command line argument provided is the correct length the else block will print the string with the persons name
    } else {
        printf("Hello %s, how is your day today?", argv[1]);
    }
    // returns 0 indicating the program executed succesfully
    return 0;
}
