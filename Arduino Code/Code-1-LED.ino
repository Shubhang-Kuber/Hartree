/*
  Acoustic Energy Harvester - DIRECT LED DRIVE (No Relay)
  
  Description:
  This code reads the LDR sensor and directly powers a small LED
  connected to Digital Pin 7. The relay module and external battery
  are NOT used in this version.
*/

// --- Constants ---
// Pin connected to the LDR's voltage divider circuit.
const int LDR_PIN = A0; 

// Pin that will now DIRECTLY power the LED.
const int LED_PIN = 7;  

// --- Threshold ---
// If the reading from the LDR is GREATER than this, it is considered dark.
// Adjust this value after testing with the Serial Monitor.
const int DARKNESS_THRESHOLD = 500; 


void setup() {
  Serial.begin(9600); 

  // Configure the LED pin as an OUTPUT.
  pinMode(LED_PIN, OUTPUT);
  
  // Start with the LED off.
  digitalWrite(LED_PIN, LOW);
  
  Serial.println("System Initialized for Direct LED Drive.");
}


void loop() {
  // Read the current light level.
  int ldrValue = analogRead(LDR_PIN);

  // (For Debugging) Print the reading.
  Serial.print("LDR Reading: ");
  Serial.println(ldrValue);
  
  // Check if it is dark.
  if (ldrValue > DARKNESS_THRESHOLD) {
    // It's dark, so turn the LED ON.
    Serial.println(" -> Dark detected. Turning LED ON.");
    digitalWrite(LED_PIN, HIGH);
  } 
  else {
   digitalWrite(LED_PIN, LOW);
  }
}



