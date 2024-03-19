#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void copyString(char original[]);
#define MAX 21
int main() {

    char original[MAX];
    char copy[MAX];
    printf("Enter string: \n");
    fgets(original, 20, stdin);
    strcpy(copy, original);
    printf("strcpy library function: %s\n", copy);
    copyString(original);
    
    return 0;
}

void copyString(char original[]) {
    char copy[MAX];
    for(int i = 0; i < MAX; i++) {
        copy[i] = original[i];
    }
    printf("copyString method: %s\n", copy);
}