/*
 * BOOK 4 Project 5: LED Chase Effect
 */
 
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11};
int ledDelay(65);
int direction = 1;
int currentLED = 0;
unsigned long changeTime;

void setup(){
  for (int x=0; x<8; x++){
    pinMode(ledPin[x], OUTPUT);
  }
  changeTime = millis();
}

void loop(){
  if ((millis() - changeTime) > ledDelay){
      changeLED();
      changeTime = millis();
    }
}

void changeLED(){
  for (int x=0; x<8; x++){
    digitalWrite(ledPin[x], LOW);
  }
  digitalWrite(ledPin[currentLED], HIGH);
  currentLED += direction;
  if (currentLED == 7) {direction = -1;}
  if (currentLED == 0) {direction = 1;}
}
