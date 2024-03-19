// C++ code
// (C)_Isaac Lindegren Ternbom, Karl Eriksson, Malte Bengtsson, group 20 (2024)
// Work package 6
// Exercise 1.1 (task 1)
// Submission code: 271070

// WP 6 Exercise 1 Template DIT 632
#define ENCA 2
#define ENCB 3
#define PWM1 5
#define PWM2 6
 
int rotation = 0;	//Desired rotation (clockwise or counter clockwise)
int speed = 0; // Desired motor speed

void setup() {
 
  Serial.begin(9600);
  pinMode(ENCA,INPUT_PULLUP);
  pinMode(ENCB,INPUT_PULLUP);
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);  
  
  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(PWM2, 10); 
  delay(1000); // TinkerCad bug
  analogWrite(PWM1, 10);
}

void loop() {
  // Stop the motor, but not to zero because then TinkerCad dies....
  analogWrite(PWM1, 10);
  delay(1000); // TinkerCad...bug
  analogWrite(PWM2, 10);
  // Get input
  speed = getSpeed();		// set speed variable to the return value of getSpeed function
  rotation = getRotation();	// set rotation variable to the return value of the getRotation function
  while(1) {		// infinite while loop to keep motor rotating forever after choosing speed/rotation 
  if(rotation == 0) {		// checks if the chosen rotation equals 0 (indicating clockwise rotation))))
	  analogWrite(PWM1, speed);	// write the chosen speed to pin 5
	  analogWrite(PWM2, 0);		//write 0 to pin 6
	} else if(rotation == 1) { 	// checks if the chosen rotation equals 0 (indicating counter-clockwise rotation)
	  analogWrite(PWM1, 0);		// write 0 to pin 5
	  analogWrite(PWM2, speed);	// write the speed to pin 6
	}
  }
} 

int getSpeed(){
  int ready = 0;
  char buf[3];
  int input = -1;
  
  Serial.print("Please enter the desired speed: \n");
  while(!ready){
    ready = Serial.readBytes(buf,3);
    input = atoi(&buf[0]);
  }
  return input;
}

int getRotation() {		// function for getting the desired rotation from the user
  int ready = 0;		//  int variable to handle the while loop on line  62
  char buf[3];		// char array to store the user input
  int input = -1;		// variable to store the converted user input
  
  Serial.print("Please enter the desired rotation (0 for clockwise, 1 for counter clockwise): \n");
  while(!ready){		// loop while not ready (when ready does not equal 0)
    ready = Serial.readBytes(buf,3);	// set variable ready to equal reading bytes to buffer
    input = atoi(&buf[0]);	// set input to equal the int value of the user input using atoi function
  }
  return input;	// return the user input
}