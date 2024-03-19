#include <stdio.h>      // include stdio header file for input/output
#include <stdlib.h>     // include stdlib header file for general purpose library

typedef struct q {      // define struct 
    int number;     //member integer number for the current value in the node 
    struct q *next;     //member pointer next next that points to the next number in the list 
    struct q *prev;     //member pointer prev that points to the previous number in the list
} REGTYPE;

REGTYPE *addNumbers(int num);       // initialize function for adding numbers to fibonacci sequence, takes an integer as parameter

int main(int argc, char *argv[])        // main function
{
    int num = atoi(argv[1]);        // initalize number variable and set its value to the second command line argument using atoi method
    if(argc != 2) {     // checks if the number of arguments does not equal 2
        printf("%s", "invalid input");
        return 0;       // return 0, indicating succesful execution of the program
    } else if(num <= 0) {       // checks if the number input as a command line argument is less than or equal to 0
        printf("%s", "0");
        return 0;       // return 0, indicating succesful execution of the program
    }
    REGTYPE *current;       //initalize a pointer of regtype
    current = addNumbers(num);      // set pointer current to point to the last element in the fibonacci sequence
    printf("Nr %d ", current->number);
    while (current != NULL) {       // while loop for going back to the start of the linked list
        REGTYPE *previous = current-> prev;     // initalize previous to the previous current
        free(current);      //free current node 
        current = previous;        // set current to previous node each iteration until the first element is reached
    }
    return 0;        // return 0, indicating succesful execution of the program
}

REGTYPE *addNumbers(int num) {        // implementation of function for adding the fibonacci sequence numbers
    REGTYPE *head, *second, *old, *new;     // pointers to handle the list nodes
    head = malloc(sizeof(REGTYPE));     //allocate memory for the head node
    head->number = 0;       //set the number value of the head node to 0
    head->prev = NULL;      //set the previous node to NULL
    head->next = NULL;      //set the next node to NULL

    if(num == 1) {      //checks if the passed parameter num is equal to 1
        return head;        // return the head node
    }
    second = malloc(sizeof(REGTYPE));       //allocate memory for the second node in the list
    second->number = 1;     // set the value of the number in the second node to 1
    second->next = NULL;        // set value of the second node -> next to NULL
    second->prev = head;        // set the value of the second node -> prev to head
    head->next = second;        // set the value of the head node -> next to second node
    old = second;       // set the old node to the second node 

    if(num == 2) {      // checks if the passed parameter num is equal to 2
        return second;      //return the second node
    }
    for (int i = 2; i < num; i++) {       // loop over the remaining numbers to add to the list
        new = malloc(sizeof(REGTYPE));      //allocate memory for the new node 
        new->prev = old;        //set the new -> prev to old node
        new->next = NULL;       //set the new -> next to NULL
        int num = old->number + old->prev->number;      // initialize variable num to set the current number to the old number + old's previous number
        new->number = num;      // set the new -> number to the num above
        old->next = new;        // set the old -> next to the new node
        old = new;      //set old node to new node
    }
    return new;     //return the new node (the last one in the list)
}
