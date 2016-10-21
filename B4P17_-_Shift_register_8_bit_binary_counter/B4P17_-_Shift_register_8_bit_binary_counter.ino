/*
 * BOOK 4 Project 17: shift register 8─bit binary counter
 *
 * Pin configuration of a 595 shift register:
 *
 *                       __                __
 *     Vcc   Q0    DS    OE    STCP  SHCP  MR    Q7S
 *     
 *     16    15    14    13    12    11    10    09
 *    ┌┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─┐
 *    |                  SN74HC595N                |
 *    | ()                                         |
 *    └┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─┘
 *     01    02    03    04    05    06    07    08
 *     
 *     Q1    Q2    Q3    Q4    Q5    Q6    Q7    GND
 *
 *
 *     Lengend  Pin   Description
 *     --------------------------------------------
 *     Q0-Q7    1-7   Parallel data out 1-7
 *     GND      08    Ground (0 V)
 *     Q7S      09    Serial data out
 *     MR       10    Master reset (active LOW)
 *     SHCP     11    Shift register clock in
 *     STCP     12    Storage register clock in
 *     OE       13    Output enable input (active LOW)
 *     DS       14    Serial data in
 *     Q0       15    Parallel data out 0
 *     Vcc      16    Supply voltage
 *
 *
 */


int latchPin = 8;   // Pin to STCP (12)
int clockPin = 12;  // Pin to SHCP (11)
int dataPin  = 11;  // Pin to DS   (14)

void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin,  OUTPUT);
}

void loop(){
  
  for (int i = 0; i < 256; i++){

    digitalWrite(latchPin, LOW); //allow data flow
    shiftOut(i);
    digitalWrite(latchPin, HIGH); //lock and send data
    delay(200);
    
  }

}

void shiftOut(byte dataOut){

    boolean pinState;
    digitalWrite(dataPin, LOW); //clear shift register for sending data
    digitalWrite(clockPin, LOW);

    for(int i=0; i<8; i++){ 
      
      //for each bit in dataOut, send out a bit

      digitalWrite(clockPin, LOW); //set clockPin to Low prior to sending bit

      if (dataOut & 1 << i ){

        pinState = HIGH;

      }else{

        pinState = LOW;
      }

      //Set dataPin to H or L depending on pinState

      digitalWrite(dataPin, pinState); // Send bit out on rising edge of clock
      digitalWrite(clockPin, HIGH);
      
    }

    digitalWrite(clockPin, LOW); //Stop shifting data
}
