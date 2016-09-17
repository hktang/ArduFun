/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(2, OUTPUT);
  pinMode(8, OUTPUT);
}

void beepS(){
  for (int i = 0; i < 3; i++){
    // Morse for S
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    delay(100);
  }  
}

void beepO(){
  for (int i = 0; i < 3; i++){
    // Morse for O
    digitalWrite(8, HIGH);
    delay(300);
    digitalWrite(8, LOW);
    delay(300);
  }  
}

// the loop function runs over and over again forever
void loop() {
  beepS();
  beepO();
  beepS();
  delay(500);
}
