/*
You should write a program to manage a database of persons. The database should be stored as a binary file
(this is important – binary, not text file!). The structure of the program is easiest to understand by reading the
description and the program skeleton below.
From the main program you should be able to choose between these options:
1 Create a new and delete the old file.
2 Add a new person to the file.
3 Search for a person in the file.
4 Print out all in the file.
5 Exit the program.
After entered the choice the program executes the task and returns to the menu for new choices.
1. Create a new and delete the old file.
Program creates a new file with the specified filename (hardcoded, fixed) and writes a first dummy record to
the file and then close it.
2. Add a new person to the file.
Gives an opportunity to put in one new person to a temp record and then add this record in
the end of the file.
3. Search for a person in the file.
Gives you an opportunity to search for all persons with either a specified first name or
family name (by choice). The program prints out all persons with that name.
4. Print out all in file.
Prints out the whole list
5. Exit the program.
Just exits the program.

You should make the program fail-safe, in particular:
• Checking if the file exists
• Checking if the list is empty
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_NAME 20
// -----typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;
// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void); // Prints out all persons in the file
void search_by_firstname(char *name); // Prints out the person if in list
void append_file(PERSON *inrecord); // appends a new person to the file

int main(void){     //main function
    int userChoice = 0;     //initialize int variable for the users choice to 0
    char name[MAX_NAME];        // initialize char array to store a name with MAX_LENGTH as number of indexes
    PERSON ppost;       //initialize a PERSON struct
    strcpy(ppost.firstname, "John");        // use strcopy method to set the first name in the ppost struct instance 
    strcpy(ppost.famname, "Doe");       // use strcopy method to set the fam name in the ppost struct instance 
    strcpy(ppost.pers_number, "19001010123a");      // use strcopy method to set the personnummer in the ppost struct instance 

    while(userChoice != 5) {        //while loop that continues as long as the user does not enter 5
        printf("1 Create a new and delete the old file.\n2 Add a new person to the file.\n3 Search for a person in the file.\n4 Print out all in the file.\n5 Exit the program.\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);       //scan the integer value the user input 
        getchar();      //clear buffer
        switch(userChoice) {        //switch case for switching between what the int variable has stored that the user input
            case 1:     //case 1
                write_new_file(&ppost);     // call method write_new_file and pass the PERSON struct instance ppost as a parameter
                break;      //break
            case 2:     //case 2
                PERSON new_person;      // initialize a new PERSON struct
                printf("Enter the new persons first name: ");
                scanf("%19s", new_person.firstname);        //store what the user input into the new_person instance first name member
                printf("Enter the new person's last name: ");
                scanf("%19s", new_person.famname);      //store what the user input into the new_person instance family name member
                printf("Enter the new person's personal number: ");
                scanf("%12s", new_person.pers_number);      //store what the user input into the new_person instance personnummer member
                append_file(&new_person);       //call the append_file method and pass the new_person instance as a parameter 
                break;      //break
            case 3:     //case 3
                printf("Enter the name of the person you are searching for: ");
                fgets(name, sizeof(name), stdin);       //use fgets method to get the name of the person the user is searching for and put it in char array name
                search_by_firstname(name);      //call search_by_firstname method and pass the name input by the user as parameter
                break;      //break
            case 4:     //case 4
                printfile();        // call the printfile method
                break;      //break
            case 5:     //case 5
                userChoice = 5;     //set user choice to 5
                break;      //break
            default:        //default, if none of the other switch cases are entered
                printf("Invalid input, please choose a number between 1-5\n");
            break;      //break
        }
    }
    return(0);      //return 0, indicating succesful execution of the program
}

void write_new_file(PERSON *inrecord) {    // Creates a file and writes the first record, takes the address to a PERSON struct as parameter
    FILE* fileptr;      //initialize FILE pointer variable
    fileptr=fopen("personDB", "wb");        // set the fileptr variable to equal the fopen function, which takes the file name and wb as paramaters (wb meaning write to binary)
    fwrite(inrecord, sizeof(PERSON), 1, fileptr);       //use fwrite functino to write the passed parameter, with the size of a PERSON struct, the number 1 (number of elements), and the pointer to a FILE object output stream
    fclose(fileptr);        //close the file stream
} 

void printfile(void) {       // Prints out all persons in the file
    FILE *fileptr;      //initialize FILE pointer variable
    PERSON person;      //initialize PERSON struct 
    if((fileptr=fopen("personDB", "rb")) == NULL) {     // checks if the file that is being opened exists
        printf("Unable to open the file\n");
        return;     // return from function
    }
    while (fread(&person, sizeof(PERSON), 1, fileptr)) {    //loops while there is something in the file to read
        printf("First Name: %s\nLast Name: %s\nPersonal Number: %s\n", person.firstname, person.famname, person.pers_number);
    }
    fclose(fileptr);        //close the file stream
}

void search_by_firstname(char *name) {      // Prints out the person if in list
    FILE *fileptr;      //initialize FILE pointer variable
    PERSON person;      //initialize PERSON struct
    if((fileptr=fopen("personDB", "rb")) == NULL) {      // checks if the file that is being opened exists
        printf("Unable to open the file\n");
        return;      // return from method
    }   
    while (fread(&person, sizeof(PERSON), 1, fileptr)) {        //loops while there is something in the file to read
        if(strncasecmp(person.firstname, name, strlen(person.firstname)) == 0 || strncasecmp(person.famname, name, strlen(person.famname)) == 0) {      // checks if the current person first name, or current person last name is equal to the passed parameter name
            printf("\nPerson: %s %s %s\n", person.firstname, person.famname, person.pers_number);
        }
    }
    fclose(fileptr);        // close the file stream
}

void append_file(PERSON *inrecord) {      // appends a new person to the file
    FILE* fileptr;       //initialize FILE pointer variable
    if((fileptr=fopen("personDB", "rb")) == NULL) {     // checks if the file that is being opened exists
        printf("No file to append to");
        return;      // return from method
    } else {
        fileptr=fopen("personDB", "ab");        //  opens the file stream to append to the binary file
        fwrite(inrecord, sizeof(PERSON), 1, fileptr);       //writes the passed parameter the binary file 
        fclose(fileptr);        //closes the file stream
    }
    fclose(fileptr);        //closes the file stream
}