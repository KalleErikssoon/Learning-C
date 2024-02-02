/*
a) Write a function that creates a linked list with a NUMBER of records of type REGTYPE (see below).
The value of the variable data is given a random number between 0 and 100.
Function declaration : REGTYPE * random_list (void);
Test the function from the main() program.
b) Extend the program with a function with the function declaration:
REGTYPE * add_first (REGTYPE * temp, int data);
That adds a new record to the first position of the list and assign the field numbers the value of data.
The function must return a pointer to the new first entry in the list. Extend main() so that this
function is tested.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #### Constants #####
#define MAX 5
// ##### typedefs ####
typedef struct q {
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;
// ##### Function declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);
// ###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *act_post, *head = NULL;
    srand(time(0)); // Random seed
    head = random_list();
    head = add_first(head, (rand() % 100 ) + 1);
    act_post = head;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }
    // --- Free the allocated memory ---
    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }
    return 0;
}
// ==== End of main ======================================
REGTYPE *random_list(void)
{
    REGTYPE *top, *old, *item;
    int nr, i = 0;
    nr = (rand() % 100) + 1;
    top = malloc(sizeof(REGTYPE));
    top->prev = NULL;
    top->next = NULL;
    top->number = nr;
    old = top;
    for (size_t i = 0; i < MAX; i++)
    {
        nr = (rand() % 100) + 1;
        item = malloc(sizeof(REGTYPE));
        item->prev = old;
        item->next = NULL;
        item->number = nr;
        old->next = item;
        old = item;
    }
    return (top);
}
//==========================================================
REGTYPE *add_first(REGTYPE *temp, int data)
{
    REGTYPE *newFirst;
    newFirst = malloc(sizeof(REGTYPE));
    newFirst->next = temp;
    newFirst->prev = NULL;
    newFirst->number = data;
    temp->prev = newFirst;
    free(newFirst);
    return newFirst;
}