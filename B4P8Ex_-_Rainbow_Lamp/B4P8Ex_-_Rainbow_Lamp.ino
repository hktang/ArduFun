/*
 * BOOK 4 Project 8 Ex: Rainbow lamp
 * 
 *          R    G    B
 * violet 148,   0, 211
 * indigo  75,   0, 130
 * blue     0,   0, 255
 * green    0, 255,   0
 * yellow 255, 255,   0
 * orange 255, 127,   0
 * red    255,   0,   0
 */


//R, G, B values for each of VIBGYOR colors
int r[] = {148, 75, 0, 0, 255, 255, 255}; 
int g[] = {0, 0, 0, 255, 255, 127, 0};
int b[] = {211, 130, 255, 0, 0, 0, 0};

//output PWN values (0-255) for each pin
int rLedVal, 
    gLedVal, 
    bLedVal;

//defaut delay time
int delayTime = 100;

//pin numbers for R, G, B output and potentiometer input
int rPin = 11;
int gPin = 10;
int bPin = 9;
int potPin = 2;

void setup(){
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop(){
  for (int x=6; x>=0; x--){

    int rNow = r[x];
    int gNow = g[x];
    int bNow = b[x];

    int rNext, gNext, bNext;
    
    if (x != 0){
      rNext = r[x-1];
      gNext = g[x-1];
      bNext = b[x-1];
    }else{
      rNext = r[6];
      gNext = g[6];
      bNext = b[6];
    }
    
    writeRgb(rNow, gNow, bNow);

    //delay(analogRead(potPin));
    transition(analogRead(potPin), rNow, gNow, bNow, rNext, gNext, bNext);
  }
}

void writeRgb(int r, int g, int b){
    analogWrite(rPin, r);
    analogWrite(gPin, g);
    analogWrite(bPin, b);
}

void transition(int duration, int r, int g, int b, int rNext, int gNext, int bNext){
  int steps = 100;

  int rStep = int((r - rNext) / steps);
  int gStep = int((g - gNext) / steps);
  int bStep = int((b - bNext) / steps);
  
  for (int x=0; x<steps; x++){
    r = r + rStep;
    g = g + gStep;
    b = b + bStep;
    writeRgb(r,g,b);
    delay(constrain(duration, 10, 20));
  }
}

