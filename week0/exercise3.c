// include input/output header filer
#include <stdio.h>
// include string header file for string operations
#include <string.h>
// Main function in the program, no program arguments supported
int main (int argc, char* argsv[]) {
    // if there is no argument (except for file name) inform user
    if(argc == 1) {
        printf("No argument provided");
    // if the user provides more than one argument (except for file name) inform user 
    } else if (argc > 2) {
        printf("Too many arguments provided");
        //if the user provided argument equals -h inform how the program works
    } else if (strcmp(argsv[1], "-h") == 0) {
        printf("This program prints your name, you can provide your name as 1 and only 1 command line argument");
    } else {
        printf("Hello World! - I'm %s", argsv[1]); 
    }
    //return 0, indicating the program executed successfully
    return 0;
}