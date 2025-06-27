const byte segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
const byte digitPins[2] = {9, 10};

const byte digitCodes[10][7] = {
  {0, 0, 0, 0, 0, 0, 1}, 
  {1, 0, 0, 1, 1, 1, 1}, 
  {0, 0, 1, 0, 0, 1, 0}, 
  {0, 0, 0, 0, 1, 1, 0}, 
  {1, 0, 0, 1, 1, 0, 0}, 
  {0, 1, 0, 0, 1, 0, 0}, 
  {0, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1}, 
  {0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 0, 0}  
};

int count = 1;
bool countingUp = true;
unsigned long lastUpdate = 0;
const unsigned long interval = 500; 

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  
  if (currentMillis - lastUpdate >= interval) {
    lastUpdate = currentMillis;

    if (countingUp) {
      count++;
      if (count > 40) countingUp = false;
    } else {
      count--;
      if (count < 1) countingUp = true;
    }
  }

  
int ones = count % 10;
int tens = count / 10;

digitalWrite(digitPins[0], LOW);   
digitalWrite(digitPins[1], HIGH); 
setSegments(digitCodes[ones]);
delay(65);

  
digitalWrite(digitPins[0], HIGH);  
digitalWrite(digitPins[1], LOW);   
setSegments(digitCodes[tens]);
delay(65);
}

void setSegments(const byte *segments) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], segments[i]);
  }
}
