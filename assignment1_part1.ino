// Define the pin number for the LED and the button
const int ledPin = 7;
const int buttonPin = 2;

// Array holding different brightness levels for the LED (0 = off, 255 = fully on)
int brightnessLevels[] = {0, 85, 170, 255}; 
int currentLevel = 0;               // Tracks the current brightness level (index in brightnessLevels)
bool lastButtonState = LOW;        // Remembers the previous state of the button
bool buttonPressed = false;        // Tracks if a valid button press occurred

void setup() {
  pinMode(ledPin, OUTPUT);         // Set LED pin as output
  pinMode(buttonPin, INPUT);       // Set button pin as input
}

void loop() {
  // Read the current state of the button (HIGH when pressed)
  bool buttonState = digitalRead(buttonPin);

  // Detect the moment the button is first pressed (rising edge)
  if (buttonState == HIGH && lastButtonState == LOW) {
    buttonPressed = true;
  }

  // If a button press was detected, update the brightness level
  if (buttonPressed) {
    currentLevel = (currentLevel + 1) % 4; // Cycle through brightness levels 0–3
    analogWrite(ledPin, brightnessLevels[currentLevel]); // Apply new brightness to LED
    buttonPressed = false; // Reset press detection
    delay(200); // Debounce delay to prevent multiple triggers from one press
  }

  // Update the last button state for next loop iteration
  lastButtonState = buttonState;
}
