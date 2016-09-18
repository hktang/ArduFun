/*
 * BOOK 4 Project 7: pulsating lamp
 */
 
int ledPin = 11;
float sinVal;
int ledVal;

void setup(){
  pinMode(ledPin, OUTPUT);
}

void loop(){
  for(int x=0; x<180; x++){
    
    //convert x degree to radian, then get sin() of radian
    sinVal = sin(x*(3.14159/180)); 
    
    //cast sin value to ledVal of 0 to 255
    ledVal = int(sinVal * 255); 

    analogWrite(ledPin, ledVal);
    delay(1000/180);
  }
}

