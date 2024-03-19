#include <stdio.h>      //include stdio header file for input/output
#include <string.h>     //include string header file for string operations
#define NUM_OF_STRINGS 5  // define number of strings to 5
#define MAX_LENGTH 251     // define MAX_LENGTH of each string to 251
void removeShortestAndPrint(char *wholeString);     //initalize function for removing shortest strin and printing, taking pointer to char as parameter
int main() {    //main function

    char tempString[MAX_LENGTH];        //initalize tempString char array
    char wholeString[(MAX_LENGTH * NUM_OF_STRINGS) + 5 + 1] = "";        //initalize whole string (all 5 strings in one array), set space to the MAX_LENGTH * NUM_OF_STRINGS in total + 5 for space/new line between each string, + 1 for NULL terminator

    for(int i = 0; i < NUM_OF_STRINGS; i++) {   //loop over the amount of strings 
        printf("Enter String #%d: ", i + 1);
        fgets(tempString, sizeof(tempString), stdin);      // use fgets to get the string the user inputs
        strcat(wholeString, tempString);        //concatenate the input string to the wholeString array of characters
    }
    printf("String before removal: \n%s", wholeString);
    removeShortestAndPrint(wholeString);        // call function to remove shortest string and print
}

void removeShortestAndPrint(char *wholeString) {        //implementation of function to remove shortest string and print
    int start = 0, end = 0;     //initalize int variables for start and end indexes
    //initalize variables for current length/position, for the shortest length so far, and shortest start/end indexes so far
    int currLength = 0, currentPosition = 0, shortestLength = MAX_LENGTH, shortestStart = 0, shortestEnd = MAX_LENGTH;
    for(int i = 0; wholeString[i] != '\0'; i++) {       // loop as long as wholeString does not equal \0
        if(wholeString[i] == '\n') {    //checks if the current index in wholestring char array equals new line
            end = i;        // set end variable to equal i
            currLength = end - start;       // calculate value of currLength by subtracting start from end
             if (currLength < shortestLength) {     // checks if the current length is less than the shortest length
                shortestLength = currLength;        // set shortest length to current length
                shortestStart = start;      // set shortest start to start
                shortestEnd = end;          //set shortest end to end
            }
            start = i + 1;      // set start to the next index (i + 1)
        }   
    }
    printf("%s", "Shortest string removed: ");
    for (int i = shortestStart; i <= shortestEnd; i++) {        // loop over the indexes between shortest start and shortest end
        printf("%c", wholeString[i]);
    }
    printf("%s", "Array after removal:\n");
    char tempString[(MAX_LENGTH * 5) + 5];      // initalize char array for temporary string
    strncpy(tempString, wholeString, shortestStart);        // copy the whole string into the temp string, until the shortest start index
    int remainingLength = strlen(wholeString) - shortestEnd;        // calcaulate the remaining length by subtracting the shortestEnd from the length of wholestring
    strncat(tempString, &wholeString[shortestEnd + 1], remainingLength);        // concatenate tempString with wholeString from index shortestEnd + 1 (ignoring space), until remaining length
    strcpy(wholeString, tempString); // copy temp string into whole string
    printf("%s", wholeString);
}
