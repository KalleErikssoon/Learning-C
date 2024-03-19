#include <stdio.h>      // include stdio header file for input/output 
#include <stdlib.h>     // include stdlib header file (general purpose standard library)
#include <string.h>     //include string header file for string operations
#define TRUE 1      //defines TRUE as 1
#define FALSE 0     //defines FALSE as 0
#define MAX 4       // defines MAX as 4
//initalize void method clearBuffer
void clearBuffer();
//initalize calcAndPrint method, takes two pointers to int arrays, integer rows and integer columns as parameters
void calcAndPrint(int *firstValues, int *secondValues, int rows, int columns);
// initalize getValues method, takes pointer to int array, integer expectedLength and integer currentMatrix as parameters  
int getValues(int *values, int expectedLength, int currentMatrix);      

int main() {        //main function
    
    int rows, columns;      //initalize int variables for rows and columns
    printf("Input the size: ");
    scanf("%d%d", &rows, &columns);     //scan user input for rows and columns
    if(rows > MAX || columns > MAX) {       //checks if the rows or columns is > 4 
        printf("Invalid input, maximum size is 4x4");
        return 0;       //return 0, indicating succesful execution of the program
    } if (rows == 1 && columns == 1) {      //checks if rows and columns equal 1
        printf("Invalid input, must be > 1x1");
        return 0;      //return 0, indicating succesful execution of the program 
    }
    clearBuffer();      //call clearBuffer method
    int length = rows * columns;        //initalize length array to be equal to rows multiplied by columns 
    int firstMatrix[length];        //initialize int array for the first matrix values
    int secondMatrix[length];       //initalize int array for the second matrix values
    int currentMatrix = 1;          // initalize current matrix to be equal to 1
    int firstInput, secondInput;        //initalize first and second input int variables
    firstInput = getValues(firstMatrix, length, currentMatrix);     // set first input int to equal the return value of calling getValues method
    currentMatrix++;        // increment currentMatrix by 1
    secondInput = getValues(secondMatrix, length, currentMatrix);       //set first input int to equal the return value of calling getValues method
    if(firstInput == TRUE && secondInput == TRUE) {     // checks if the returned values from getValues are equal to TRUE (integer value 1)
    calcAndPrint(firstMatrix, secondMatrix, rows, columns);     //call calcAndPrint method 
    } else {        //else
        printf("Invalid input");
    }
    return 0;       // return 0, indicating succesful execution of the program 
}
//implementation of calcAndPrint method, takes two pointers to int arrays, integer rows and integer columns as parameters 
void calcAndPrint(int *firstValues, int *secondValues, int rows, int columns) { 
    int results[rows][columns];     //initialize 2d array with its rows equal to passed parameter rows, and columns equal to the passed parameter columns
    int k = 0;      //initalize variable k to 0
    for(int i = 0; i < rows; i++) {     // outer loop, going over each row
        for (int j = 0; j < columns; j++) {     //inner loop, going over each column
            results[i][j] = firstValues[k] + secondValues[k]; //set the value at the current row and column equal to the current values at position k in both passed pointers to arrays 
            k++;        //increment k
        }
    }
    printf("The sum is: ");
     for(int i = 0; i < rows; i++) {        // outer loop, going over each row
        printf("\n");
        for(int j = 0; j < columns; j++) {      // inner loop, going over each column
            printf("%d ", results[i][j]);
        }
    }

}
 // implementation of getValues method, takes pointer to int array, integer expectedLength and integer currentMatrix as parameters
int getValues(int *values, int expectedLength, int currentMatrix) {  
    char userInput[20];     //initalize char array for user input
    int count = 0, number, charsRead;      //initalize int variables count to 0, number and charsRead
    printf("input the elements of matrix %d: ", currentMatrix);
    fgets(userInput, sizeof(userInput) - 1, stdin);     // use fgets to scan userInput, 
    char* ptr = userInput;      // initalize char pointer to equal the first address in userInput char array
    while (sscanf(ptr, "%d%n", &number, &charsRead) == 1) {     //while loop as long as the return value of sscanf == 1
        if (count < expectedLength) {       // checks if the count is less than the expected length 
            values[count] = number;     // set the value at position count in passed pointer to int array to be equal to the number scanned 
            count++;        //increment count variable
            ptr += charsRead;       // set pointer to point at the next address after the current amount of read characters
        }
    }
    if(count != expectedLength) {       //checks if count is not equal to the expected length
        return FALSE;       //return FALSE (0)
    } 
    return TRUE;        // return TRUE (1)
}
//method to clear buffer
void clearBuffer() {
    int c;      //initialize int variable c
    while((c = getchar()) != '\n' && c != EOF) {}   // get the next char while it does not equal end of line (\n) and it does not equal end of file
}