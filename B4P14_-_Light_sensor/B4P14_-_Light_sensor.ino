/*
 * BOOK 4 Project 14: Light sensor
 */

int piezoPin = 8;
int ledPin = 7;
int ldrPin = 0;
int ldrValue = 0; //use 10k resistor will work

void setup(){

}

void loop(){

  ldrValue = analogRead(ldrPin);
  tone(piezoPin, 1000);
  digitalWrite(ledPin, HIGH);
  delay(25);
  noTone(piezoPin);
  digitalWrite(ledPin, LOW);
  delay(ldrValue * 5);
}

