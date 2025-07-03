const int ledPin = 7;
const int buttonPin = 2;

int brightnessLevels[] = {0, 85, 170, 255}; 
int currentLevel = 0;
bool lastButtonState = LOW;
bool buttonPressed = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    buttonPressed = true;
  }

  if (buttonPressed) {
    currentLevel = (currentLevel + 1) % 4;
    analogWrite(ledPin, brightnessLevels[currentLevel]);
    buttonPressed = false;
    delay(200); // debounce
  }

  lastButtonState = buttonState;
}
