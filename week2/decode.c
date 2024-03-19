int hexToInt(char hex);     //initialize hexToInt function that returns an integer and takes a character as parameter
void decToBinAndPrint(int firstDec, int secondDec);     ////initialize decToBin void function that takes two int numbers as parameter 
int calcSecondNum(char num[3]);     //initialize calcSecondNUm function that returns an int and takes a char array as parameter 
int calcThirdNum(char num[2]);      //initialize calcThirdNum function that returns an int and takes a char array as parameter 
#include <stdio.h>      //include stdio header file for input/output
#include <string.h>     // include string header file for string operations
#include <stdlib.h>     // include stdlib header file (general purpose standard library)

int main(int argc, char *argv[]) {      // main function

    int firstValue, secondValue;        // initialize int variables for first and second hex value that will be stored 
    if(argc != 2 || strlen(argv[1]) > 2) {      // checks if the amount of arguments does not equal 2, or if the length of the second argument of the char array is larger than 2
        printf("%s", "Invalid input, too many arguments (max 1 argument) or too long argument (max 2 characters)");
        return 0;       //return 0, indicating succesful execution of the proram
    } else if(strlen(argv[1]) < 2) {
        firstValue = hexToInt(argv[1][0]);      // convert the first character from hex to int using the hexToInt function
        secondValue = 0;        // set second int value to 0  
    } else {
        firstValue = hexToInt(argv[1][0]); // convert the first character from hex to int using the hexToInt function
        secondValue = hexToInt(argv[1][1]); // convert the first character from hex to int using the hexToInt function
    }
    decToBinAndPrint(firstValue, secondValue);      //pass the first and second decimal value to the functino decToBinAndPrint
    return 0;   //return 0, indicating succesful execution of the proram
}

int hexToInt(char hex) {    //function to convert hex value to integer value
    if (hex >= '0' && hex <= '9') {     //checks if the character is between '0' and '9'
        return hex - '0';       // convert character to its integer value
    }
    else if (hex >= 'A' && hex <= 'C') {    // checks if the character is between 'A' and 'C'
        return hex - 'A' + 10;   // convert character to its integer value (10-12)
    }
    else if (hex >= 'a' && hex <= 'c') {    // checks if the character is between 'a' and 'c'
        return hex - 'a' + 10;      // convert character to its integer value (10-12)
    }
    else {
        return -1;      //return -1 to indicate that the value passed to function was not valid
    }
}
void decToBinAndPrint(int firstDec, int secondDec) {    //void function that takes 2 integer values as parameters
    int engine_on = 0, gear_pos = 0, key_pos = 0, brake1 = 0, brake2 = 0;       //initialize int variables to store the values for each part that will be printed
    unsigned int firstMask = 1 << 3, secondMask = 1 << 3;   // initialize unsigned int firstMask and secondMask and left shift 4 bits
    int firstVal = firstDec, secondVal = secondDec;     //initialize firstValue and secondValue to first and second decimal number being passed as parameters
    char firstBinary[5];        //initialize char array to store each bit of first decimal variable
    char secondBinary[5];       //initialize char array to store each bit of second decimal variable
    if(firstDec == 0) {
        engine_on = 0;      //set engine_on value to 0
        gear_pos = 0;       //set gear_pos value to 0
    }
    else {
        for(int i = 0; i < 4; i++) {    // loop over the length of this part of the bit (always 4 bits)
            if (firstVal & firstMask) {     // checks if the value & mask are true
                firstBinary[i] = '1';       // set value at position i in array to 1
            } 
            else {
                firstBinary[i] = '0';       // set value at position i in array to 0
            }
        firstMask >>= 1;    // right shift the mask by 1 bit 
        }
        engine_on = (firstBinary[0] > '0') ? 1 : 0;     //if the value at index 0 in firstBinary array is > 0 set engine_on value to 1, else to 0
        gear_pos = calcSecondNum(firstBinary);      //calculate int value of gear position by calling function calcSecondNum
    } 
    if(firstDec == 8) {     // checks if firstDec is equal to 8
        engine_on = 1;      //set engine_on to 1
        gear_pos = 0;       // set gear_pos to 0
    } else if(firstDec > 4 && firstDec < 8) {   //checks if the first decimal value is between 5 and 7 
        printf("invalid input");
        return;     //return from function
    }
    if(secondDec == 0) {    // checks if the second decimal value is 0
        key_pos = 0;    // set key_pos to 0
        brake1 = 0;     //set brake1 to 0
        brake2 = 0;     //set brake1 to 0
    } else {
        for(int i = 0; i < 4; i++) {        // loop over the length of this part of the bit (always 4 bits)
            if (secondVal & secondMask) {       // checks if the value & mask are true
                secondBinary[i] = '1';      // set value at position i in array to 1
            } 
            else {
                secondBinary[i] = '0';  // set value at position i in array to 0
            }
        secondMask >>= 1;   // right shift the mask by 1 bit 
        }
        key_pos = calcThirdNum(secondBinary);       //set int value of key position to return value from function calcThirdNum
        brake1 = (secondBinary[2] > '0') ? 1 : 0;   //if the value at index 2 in firstBinary array is > 0 set brake1 value to 1, else to 0
        brake2 = (secondBinary[3] > '0') ? 1 : 0;   //if the value at index 3 in firstBinary array is > 0 set brake2 value to 1, else to 0
    }
    if (gear_pos == -1 || key_pos == -1) {      // if the gear_pos or key_pos equal -1 (which is returned from the functions calcSecondNum and calcThirdNum) the input is not valid
        printf("Invalid input b, gear pos: %d, key_pos. %d\n", gear_pos, key_pos);
        return;     //return if the input is invalid
    } else {
    printf("Name     Value\n");
    printf("-----------------------------\n");
    printf("engine_on %d\n", engine_on);
    printf("gear_pos %d\n", gear_pos);
    printf("key_pos %d\n", key_pos);
    printf("brake1 %d\n", brake1);
    printf("brake2 %d\n", brake2);
    }
}
int calcSecondNum(char num[4]) {        //initialize calcSecondNUm function that returns an int and takes a char array as parameter   
    char strToCmp[3];      //intialize char array to compare with strings 
    strToCmp[0] = num[1];       //set comparison char array to value at index 1 of char array from parameter
    strToCmp[1] = num[2];       //set comparison char array to value at index 2 of char array from parameter
    strToCmp[2] = num[3];       //set comparison char array to value at index 3 of char array from parameter
    if(strncmp(strToCmp, "000", 3) == 0) {       // checks if the char array and the string "000" are equal
        return 0;       //return 0 (decimal value of second num)
    } else if(strncmp(strToCmp, "001", 3) == 0) {            // checks if the char array and the string "001" are equal
        return 1;       // return 1 (decimal value of second num)
    } else if(strncmp(strToCmp, "010", 3) == 0) {      // checks if the char array and the string "010" are equal 
        return 2;       //return 2 (decimal value of second num)
    } else if(strncmp(strToCmp, "011", 3) == 0) {       // checks if the char array and the string "011" are equal
        return 3;       //return 3 (decimal value of second num)
    } else if (strncmp(strToCmp, "100", 3) == 0) {      // checks if the char array and the string "100" are equal
        return 4;       //return 4 (decimal value of second num)
    } else {        // else
        return -1;      //return -1 if none of the above comparisons are equal to indicate there was no match found
    }
}
int calcThirdNum(char num[4]) {     //initialize calcSecondNUm function that returns an int and takes a char array as parameter
    char strToCmp[2];       //intialize char array to compare with strings
    strToCmp[0] = num[0];   //set comparison char array to value at index 0 of char array from parameter
    strToCmp[1] = num[1];   //set comparison char array to value at index 0 of char array from parameter
    if(strncmp(strToCmp, "00", 2) == 0) {       // checks if the char array and the string "00" are equal
        return 0;       //return 0 (decimal value of third num)
    } else if(strncmp(strToCmp, "01", 2) == 0) {        // checks if the char array and the string "01" are equal
        return 1;       //return 1 (decimal value of third num)
    } else if(strncmp(strToCmp, "10", 2) == 0) {        // checks if the char array and the string "10" are equal
        return 2;       //return 2 (decimal value for third num)
    } else {        // else
        return -1;      //return -1 if none of the above comparisons are equal to indicate there was no match found
    }
}