
// Include Libraries
#include "Arduino.h"
#include "Buzzer.h"
#include "SoilMoisture.h"


// Pin Definitions
#define BUZZER_PIN_SIG	2
#define SOILMOISTURE_5V_PIN_SIG	A3



// Global variables and defines

// object initialization
Buzzer buzzer(BUZZER_PIN_SIG);
SoilMoisture soilMoisture_5v(SOILMOISTURE_5V_PIN_SIG);


// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
  
    int soilMoisture_5vVal = soilMoisture_5v.read();
    Serial.print(F("Val: ")); 
    Serial.println(soilMoisture_5vVal);
    if (soilMoisture_5vVal <= '512')
    {
    buzzer.on();       // 1. turns on
    delay(5000);             // 2. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    buzzer.off();      // 3. turns off.
    delay(5000);             // 4. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }
    else if (soilMoisture_5vVal >= '512') {
    Serial.print(" MOISTURE OK"); 

    }
       
}
