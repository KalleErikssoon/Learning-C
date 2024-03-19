#include <stdio.h>      // include stdio header file for input/output
#include <stdbool.h>
int search_number(int number, int tab[], int size);
void clearBuffer();
void sort (int number, int tab []);

int main() {    //main function

    int test[] = {1,2,34,5,67,3,23,12,13,10};
    int size = sizeof(test) / sizeof(test[0]);
    int num = 34;
    printf("Enter the number you're looking for: ");
    scanf("%d", &num);
    clearBuffer();
    int result = search_number(num, test, size);
    printf("index for the number you were looking for: %d\n", result);
    sort(size, test);
    return 0;       // return 0, indicating succesful execution of the program
}

int search_number(int number, int tab[], int size) {
    for(int i = 0; i < size; i++) {
        if(number == tab[i]) {
            return i;
        }
    }
    return -1;
}
void sort (int number, int tab []) {
    bool sorted = false;
    int size = number;
    int temp;
    while(!sorted) {
        sorted = true;
        for(int i = 0; i < size - 1; i++) {
            if(tab[i] > tab[i+1]) {
                temp = tab[i+1];
                tab[i+1] = tab[i];
                tab[i] = temp; 
                sorted = false;
            }
        }
    }
    for(int i = 0; i < size; i++) {
        printf("index: %d value: %d\n", i, tab[i]);
    }
}

void clearBuffer() {
    // get the next char while it does not equal end of line (\n) and it does not equal end of file
    while(getchar() != '\n' && getchar() != EOF) {
        // do nothing
        ;
    }
}