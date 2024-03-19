#include <Keypad.h>		//include Keypad header file

const byte ROWS = 4;	//initalize const variable for amonut of rows
const byte COLUMNS = 4;	//initalize const variable for amonut of columns
// initialize 2d char array that maps all key values as chars to their respective rows/columns 
const char allKeys[ROWS][COLUMNS] = {{'1', '2', '3', 'A'},
									{'4', '5', '6', 'B'},
									{'7', '8', '9', 'C'},
									{'*', '0', '#', 'D'}
                                   };


byte rows[ROWS] = {11, 10, 9, 8};	// array storing the ports the rows are on
byte columns[COLUMNS] = {7, 6, 5, 4};	//array storing the ports the columns are on
Keypad keyPad = Keypad( makeKeymap(allKeys), rows, columns, ROWS, COLUMNS);	// initialize Keypad object that maps to all chars, the rows and columns array, and the ROWS and COLUMNS total amounts
void setup()		//setup 
{
  Serial.begin(9600);	// sets the data rate in bits per second		
}

void loop()		//main loop
{
  char key = keyPad.getKey();      //get the key pressed and assign it to char variable key

  
  if (key) {		// checks if a key is pressed
    Serial.println(key); //print the key that was pressed
    delay(1000); 	//delay by 1 second
  }
}