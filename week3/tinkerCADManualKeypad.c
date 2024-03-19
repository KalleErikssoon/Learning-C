const byte ROWS = 4; //initalize const variable for amonut of rows
const byte COLUMNS = 4; //initalize const variable for amonut of columns
// initialize 2d char array that maps all key values as chars to their respective rows/columns
const char matrix[ROWS][COLUMNS] = {{'1', '2', '3', 'A'},
									{'4', '5', '6', 'B'},
									{'7', '8', '9', 'C'},
									{'*', '0', '#', 'D'}
                                   };

const char rows[ROWS] = {11, 10, 9, 8};	// array storing the pins the rows are on
const char columns[COLUMNS] = {7, 6, 5, 4};	//array storing the pins the columns are on

void setup() // setup function to initialize pin modes and serial communication
{
    Serial.begin(9600); // Initializes serial communication at 9600 bits per second
    for(int i = 0; i < ROWS; i++) { // for loop that iterates over each row
  	pinMode(rows[i], OUTPUT); // Sets the pin mode for the current row to OUTPUT
    pinMode(columns[i], INPUT_PULLUP); // Sets the pin mode for the current column to INPUT_PULLUP, meaning the pin will be used as an input, but if nothing else is connected to the input it should be 'pulled up' to HIGH.
  }
}

void loop()		//main loop
{
  char key = checkKeyPress();		//get the key pressed and assign it to char variable key		
  if (key != 'Z') { // checks if key char variable is not equal to 'Z'
    Serial.println(key);
    delay(1000);	//delay by 1 second
  }
}

char checkKeyPress() {		//function for checking if/what key is pressed
  for (int i = 0; i < ROWS; i++) {		//loops over all the rows
    digitalWrite(rows[i], LOW); // activate row
    for (int j = 0; j < COLUMNS; j++) {		//loops over all the columns
      if (digitalRead(columns[j]) == LOW) { // if button is pressed
        digitalWrite(rows[i], HIGH); // deactivate row before returning
        return matrix[i][j]; // return pressed key
      }
    }
    digitalWrite(rows[i], HIGH); // deactivate row
  }
  return 'Z'; // return char 'Z' if no key is pressed
}
