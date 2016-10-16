/*
 * BOOK 4 Project 12: Melody player
 * 
 * 
  */

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
#define W1  1
#define H2  0.5
#define Q4  0.25
#define E8  0.125
#define S16 0.0625

float sinVal;
int toneVal;

int tune[] = { 
  G3, G3, A3, G3, C4, B3,
  G3, G3, A3, G3, D4, C4,
  G3, G3, G4, E4, C4, C4, B3, A3,
  F4, F4, E4, C4, D4, C4
  };

float duration[] = { 
  E8, E8, Q4, Q4, Q4, H2,
  E8, E8, Q4, Q4, Q4, H2,
  E8, E8, Q4, Q4, E8, E8, Q4, H2,
  E8, E8, Q4, Q4, Q4, H2,
};

int tuneSize = sizeof(tune) / sizeof(tune[0]);

int length;

void setup() {
  pinMode(8, OUTPUT);
  length = sizeof(tune) / sizeof(tune[0]);

  
  
  for (int x = 0; x < tuneSize ; x++) {
    tune[x] *= 2;
  }

}

void loop() {
    for (int x=0; x<length; x++) {
    tone(8, tune[x]);
    delay(1500 * duration[x]);
    noTone(8);
  }

for (int x=0; x<180; x++) {
  
  // convert degrees to radians then obtain sin value
  sinVal = (sin(x*(3.1412/180)));
  
  // generate a frequency from the sin value
  toneVal = 2000+(int(sinVal*1000));
  
  tone(8, toneVal);
  
  delay(2);
}
  noTone(8);
  delay(1000);
}
