const int ledPin = 9;
const int buttonPin = 2;

int brightnessLevels[] = {255, 100, 0};
int currentLevel = 0;
bool lastButtonState = HIGH;       
bool debouncedButtonState = HIGH;   
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  analogWrite(ledPin, brightnessLevels[currentLevel]);
}

void loop() {
  bool reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != debouncedButtonState) {
      debouncedButtonState = reading;

      if (debouncedButtonState == LOW) {
        currentLevel = (currentLevel + 1) % 3;
        analogWrite(ledPin, brightnessLevels[currentLevel]);
      }
    }
  }

  lastButtonState = reading;
}

