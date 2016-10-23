/*
 *  Experiment 161023
 *  
 *  Music player with 7 Segment display using 
 *  numbered musical notation (Jianpu)
 *  
 */

int d4Pin = 13;
int piezoPin = 12;

/* Pin location for the 7 segments (a-g, and dp)
 * on the Arduino Uno board.
 */
int segments[] = {2, 3, 4, 5, 6, 7, 8, 9};

/* Segment LOW/HIGH status for showing digits 0-9 
 * and the dot on the display. 
 * See datasheet for configuration
 */
int digits[11][8] = {
 {LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH},      //0
 {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH}, //1
 {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW, HIGH},    //2
 {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, HIGH},    //3
 {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH},   //4
 {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW, HIGH},    //5
 {LOW, HIGH, LOW, LOW, LOW, LOW, LOW, HIGH},     //6
 {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},  //7
 {LOW, LOW, LOW, LOW, LOW, LOW, LOW, HIGH},       //8
 {LOW, LOW, LOW, LOW, HIGH, LOW, LOW, HIGH},       //9
 {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}  //dot
};

// Music notes and frequency
#define C3  131
#define CS3 139
#define D3  147
#define DS3 156
#define E3  165
#define F3  175
#define FS3 185
#define G3  196
#define GS3 208
#define A3  220
#define AS3 233
#define B3  247
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494
#define C5  524

// Music teompos and durations
#define W1  1      //whole
#define H2  0.5    //half
#define Q4  0.25   //quarter
#define E8  0.125  //eighth
#define S16 0.0625 //sixteenth

// The music in numbered musical notation. (The East Is Red)
int sequence[] = {5, 5, 5, 6, 2, 2, 2, 2, 
                  1, 1, 1, 6, 2, 2, 2, 2, 
                  5, 5, 5, 5, 6, 1, 6, 5, 
                  1, 1, 1, 6, 2, 2, 2, 2 
                  };

int sequenceSize = sizeof(sequence) / sizeof(sequence[0]);

int toneVal;

int tune[] = { 
  G4, G4, G4, A4, D4, D4, D4, D4,
  C4, C4, C4, A3, D4, D4, D4, D4, 
  G4, G4, G4, G4, A4, C5, A4, G4,
  C4, C4, C4, A3, D4, D4, D4, D4
  };

float toneLength = Q4;
int   toneDelay =  800;

void setup(){

  int pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 13};

  // Set all 7-Segment pins to OUTPUT
  for(int i = 0; i < sizeof(pins)/sizeof(pins[0]); i ++){
  
     pinMode(pins[i],  OUTPUT);
  
  }

  for (int x = 0; x < sequenceSize ; x++) {
    tune[x] *= 2;
  }

  pinMode(piezoPin, OUTPUT);
  
}

void loop(){

  // Accept input on digit 4
  digitalWrite(d4Pin, HIGH); 
  
  for(int i = 0; i < sequenceSize; i ++){

    showDigit(digits[sequence[i]], toneDelay);
    playTone(tune[i], piezoPin);
    
  }
  
}

void showDigit(int digit[], int delayTime){
  
  for (int i = 0; i<8; i++){
    digitalWrite(segments[i], digit[i]);
  }

}

void playTone(int tune, int piezoPin){
  
  tone(piezoPin, tune);
  delay(toneDelay * toneLength);
  //noTone(piezoPin);
  
}
