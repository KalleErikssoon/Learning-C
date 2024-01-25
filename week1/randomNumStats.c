/*
You should develop a program that calculates statistical values for an array of integers. Among other things, the
program should plot a histogram for the frequency of different numbers in the array.
You need to create an array of integers (table [MAX]) where MAX is the number of random numbers between 0
and MAXNUMBER. Then you should write a function that for each possible number between 0 – MAXNUMBER
calculates how many times the number exists in the array. The result is then stored in a new array (frequency
[]).
Finally, you should write a function that takes the array frequency [] as a parameter and draws a histogram as in
the example below.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers
// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab );
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq );
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq );
// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main (void){
    int table[MAX], n;
    int frequency[MAXNUMBER] = {0};
    create_random(table);
    count_frequency(table, frequency);
    draw_histogram(frequency);
}
void create_random(int *tab) {
    for(int i = 0; i < MAX; i++) {
        int num = rand() % MAXNUMBER + 1;
        tab[i] = num;
    }
}
void count_frequency(int *tab, int *freq) {
    for(int i = 0; i < MAX; i++) {
        int val = tab[i];
        freq[val]++;
    }
}
void draw_histogram(int * freq) {
    for(int i = 0; i < MAXNUMBER; i++) {
        if(freq[i] != 0) {
        if(i < 10) {
            printf("%d%5s", i, "");
        } else {
            printf("%d%4s", i, "");
        }
        for(int j = 0; j < freq[i]; j++) {
            printf("%c", 'X');
        }
        }
        printf("\n");
    }
}