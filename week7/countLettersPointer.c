#include <stdio.h>
#include <string.h>
/*
Write a program in C to count the number of vowels and consonants in a string using a pointer.
Test Data :
Input a string: string
Expected Output :
Number of vowels : 1
Number of consonants : 5
*/
void count(char *ptr);
int main() {
    char word[30];
    printf("%s", "Enter a word: ");
    scanf("%29s", word);
    
    count(word);
    return 0;
}


void count(char *ptr) {
    int vowelcounter = 0, consonantCounter = 0;
    
    while(*ptr != '\0') {
        if(*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u') {
            vowelcounter++;
        } else {
            consonantCounter++;
        }
        ptr++;
    }
    printf("vowels: %d\nconsonants: %d\n", vowelcounter, consonantCounter);
}