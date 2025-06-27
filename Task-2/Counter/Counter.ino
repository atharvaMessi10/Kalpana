const int ledPins[4] = {8, 9, 10, 11}; 

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int count = 0; count < 16; count++) {
   
    for (int i = 0; i < 4; i++) {
      bool bit = (count >> i) & 0x01;
      digitalWrite(ledPins[i], bit);
    }
    delay(300); 
  }
}

