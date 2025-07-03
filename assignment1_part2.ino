// ----------- Pin Definitions -----------
// These define which digital pins are connected to the RGB LED
const int redPin = 7;     // Red pin of RGB LED connected to digital pin 7
const int greenPin = 5;   // Green pin of RGB LED connected to digital pin 5
const int bluePin = 6;    // Blue pin of RGB LED connected to digital pin 6

// Analog pin connected to the light sensor (e.g., photoresistor voltage divider)
const int sensorPin = A0; // Analog input for light sensor (0-1023)
int sensorValue;          // Variable to store the sensor reading

// ----------- Setup Function -----------
// Runs once at the beginning when the Arduino is powered on or reset
void setup() {
  // Set the LED pins as output so we can control their brightness using PWM
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Set the sensor pin as input to read light levels
  pinMode(sensorPin, INPUT);

  // Start the Serial Monitor at 9600 baud rate for debugging and calibration
  Serial.begin(9600);
}

// ----------- Main Loop Function -----------
// This runs continuously after setup()
void loop() {
  // Read the light level from the sensor (returns a value from 0 to 1023)
  sensorValue = analogRead(sensorPin);

  // Print the sensor reading to the Serial Monitor
  // Useful for understanding ambient light levels and adjusting thresholds
  Serial.println(sensorValue);

  // Light level-based logic to set RGB color:
  if (sensorValue < 300) {
    // If it's dark (low light), show red to indicate darkness
    setColor(255, 0, 0); // Full red, no green, no blue
  } else if (sensorValue > 700) {
    // If it's very bright, show dim green
    // (Dim to prevent the LED from being too harsh in bright conditions)
    setColor(0, 50, 0); // Low-intensity green
  } else {
    // If it's moderate light (ambient), show blue
    setColor(0, 0, 255); // Full blue
  }

  // Small delay to prevent rapid flickering or over-sampling
  delay(200); // 200 milliseconds
}

// ----------- setColor Function -----------
// A helper function to set the LED color using PWM (Pulse Width Modulation)
// Each value can range from 0 (off) to 255 (fully on)
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);     // Set brightness of red LED
  analogWrite(greenPin, green); // Set brightness of green LED
  analogWrite(bluePin, blue);   // Set brightness of blue LED
}
