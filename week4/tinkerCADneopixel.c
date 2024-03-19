// C++ code
// (C)_Isaac Lindegren Ternbom, Karl Eriksson, Malte Bengtsson, group 20 (2024)
// Work package 4
// Exercise 3
// Submission code: 2014617

#include <Adafruit_NeoPixel.h>		// include NeoPixel header file
#define NUM_LEDS 12		//define amount of leds in the NeoPixel ring
#define interval 1000 // interval at which to update (milliseconds)
byte RED_LED = 3;		//pin for red LED
byte NEO_PIXEL = 2;		//pin for NeoPixel ring
double tempValue = 0;		// initalize variable for storing temperature value
unsigned long previousMillis = 0; // will store last time the LED was updated


//initilaize instance of the Adafruit_NeoPixel library
Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUM_LEDS, NEO_PIXEL, NEO_GRB + NEO_KHZ800);

void setup() {	// initial setup
  pinMode(RED_LED, OUTPUT);	//set the pin for the red LED to output
  ring.begin(); // initialize NeoPixel ring
  ring.show(); // initialize all pixels in NeoPixel ring to off
  Serial.begin(9600);	// initialize serial communication at 9600 bits per second
}

void loop() {	//main loop
  unsigned long currentMillis = millis();	// initialize variable for storing current milliseconds passed
	// checks if current ms passed - previous ms passed is larger/equal to the interval defined
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // save the last time the LEDs were updated

    double sensorValue = analogRead(A0);	// read value from temperature sensor
    double tempValue = map(sensorValue, 20, 358, -40, 125);	//map the temperature sensor value and assign to temperature value variable
    int ledCount = map(tempValue, -40, 125, 0, NUM_LEDS);	// map temperature value to the amount of leds
    
    displayLed(ledCount, tempValue);	// call function to display LED lights based on temperature value
  }
}
// function to display the LEDs on NeoPixel ring/red LED, takes the led count and temperature as parameters
void displayLed(int ledCount, double temp) {	
  ring.clear(); // turn off all pixels
  
  for(int i = 0; i < ledCount; i++) {	//loop over the led count passed to the function
    if(temp < 15) {	//checks if temperature parameter is less than 15
    	ring.setPixelColor(i, ring.Color(0, 0, 255)); // set color to blue
    } else if (temp < 70) {	//checks if temperature parameter is less than 70
    	ring.setPixelColor(i, ring.Color(0, 255, 0)); // set color to green
    } else {	// else 
    	ring.setPixelColor(i, ring.Color(255, 0, 0)); // Set color to red
    }
  }
  
  if(ledCount >= NUM_LEDS) {	// checks if the led count is larger than number of leds
    digitalWrite(RED_LED, HIGH); // turn on the red LED if limit is reached (all LEDs in neopixel ring are on)
  } else {	// else
    digitalWrite(RED_LED, LOW); // turn red LED off
  }
  ring.show(); // Update the ring to show the new colors
}