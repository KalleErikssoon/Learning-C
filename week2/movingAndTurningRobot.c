enum DIRECTION {N, E, S, W};
typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

#include <stdio.h>
#include <string.h>
#define MAX_STRING 20

void move(ROBOT *robot);
void turn(ROBOT *robot);

int main() {

    ROBOT robot;        //initilaize instance of ROBOT struct robot
    robot.dir = N;      // set robot direction to N
    robot.xpos = 0;     // set robot xposition to 0
    robot.ypos = 0;     //set robot yposition to 0
    int userChoice;     //initialize variable to store the user's choice
    char userInput[MAX_STRING];     // initialize char array to store the user input
    do {        //start of do-while loop
        do {        //start of inner do-while loop
        printf("Enter the robot's starting position (x and y coordinates as integers between 0-99, whitespace between the two): "); 
        scanf("%d%d", &robot.xpos, &robot.ypos);        //scan the x and y coordinate input by the user
        } while((robot.xpos < 0 || robot.xpos > 99) && (robot.ypos < 0 || robot.ypos > 99));        // loop while the user input for x and y position is less than 0 or larger than 99
        printf("Enter a string of characters \"m\" and \"t\", m for move and t for turn 90 degrees, or x to exit: ");       
        scanf("%19s", userInput);       // scan the user input for how they want the robot to move/turn
        for(int i = 0; i < strlen(userInput); i++) {        //loop for the length of the user input
            if(userInput[i] == 'm') {       //checks if the current character in the char array userInput is equal to m
                move(&robot);       //call the move function passing the address of the robot instance to the method
            } else if(userInput[i] == 't') {        // checks if the current character in the char array userInput is equal to t
                turn(&robot);       //call the turn function passing the address of the robot instance to the method
            } else if(userInput[i] == 'x'){         // checks if the current character in the char array userInput is equal to x
                userChoice = 'x';       //set the userChoice variable to character x
                break;      //break out of the while loop
            } else {
                ;       // do nothing
            }
        }
        printf("Robot Y-position: %d\nRobot X-position: %d\n", robot.ypos, robot.xpos);
        userInput[MAX_STRING] = '0';        // set the user input char array at index MAX_STRING (20) to char '0'
    } while(userChoice != 'x');     //loops while the userChoice variable does not equal character 'x'
    return 0;       //return 0, inidicating succesful execution of the program
}

void move(ROBOT *robot) {       //function for moving the robot, taking a pointer to a robot struct instance as parameter
    switch(robot->dir) {        //switch case, switching depending on the robot direction
        case N:     // case for the current direction of the robot being N
        if(robot->ypos >= 99) {     // checks if the robot y-position is larger than or equal to 99
            robot->ypos = 0;        // set the robot y-position to 0
        } else {
            robot->ypos++;      // increment the robot y-postiion
        }
        break;      //break 
        case S:     // case for the current direction of the robot being S
        if(robot->ypos <= 0) {      // checks if the robot y-position is less than or equal to 0
            robot->ypos = 99;       // set the robot y-position to 99
        } else {
            robot->ypos--;      // decrement the robot y-position
        }
        break;      //break
        case W:         // case for the current direction of the robot being W
        if(robot->xpos <= 0) {      //if the robot x-position is less than or equal to 0
            robot->xpos = 99;       // set the robot x-position to 99
        } else {
            robot->xpos--;      // decrement the robot x-position
        }
        break;      //break   
        case E:     // case for the current direction of the robot being E
        if(robot->xpos >= 99) {      // checks if the robot x-position is larger than or equal to 99
            robot->xpos = 0;         // set the robot x-position to 0
        } else {
            robot->xpos++;       // increment the robot y-postiion
        }
        break;      //break
    }
}
void turn(ROBOT *robot) {       //function for turning the robot, taking a pointer to a robot struct instance as parameter 
    switch(robot->dir) {        //switch case, switching depending on the robot direction
        case N:         // case for the current direction of the robot being N
        robot->dir = E;     //set robot direction to E
        break;      //break
        case S:         // case for the current direction of the robot being S
        robot->dir = W;     //set robot direction to W
        break;      //break
        case W:         // case for the current direction of the robot being W
        robot->dir = N;     //set robot direction to N
        break;      //break
        case E:         // case for the current direction of the robot being E
        robot->dir = S;     //set robot direction to S
        break;      //break
    }
}