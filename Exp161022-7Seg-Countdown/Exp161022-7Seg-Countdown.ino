/*
 *  Experiment 161023
 *  
 *  7 Segment countdown using Arduino pins.
 *  
 *  
 */

int d4Pin = 13;
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int dp = 9;
int segments[] = {a, b, c, d, e,f, g, dp};

int digits[10][8] = {
 {LOW, LOW, LOW, LOW, LOW, LOW, HIGH, LOW},      //0
 {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH}, //1
 {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW, HIGH},    //2
 {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, HIGH},    //3
 {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH},   //4
 {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW, HIGH},    //5
 {LOW, HIGH, LOW, LOW, LOW, LOW, LOW, HIGH},     //6
 {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},  //7
 {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW},       //8
 {LOW, LOW, LOW, LOW, HIGH, LOW, LOW, LOW}       //9
};

void setup(){

  int pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 13};

  for(int i = 0; i < sizeof(pins)/sizeof(pins[0]); i ++){
  
     pinMode(pins[i],  OUTPUT);
  
  }
  
}

void loop(){

  digitalWrite(d4Pin, HIGH); 

  for(int i = sizeof(digits)/sizeof(digits[0]); i > 0; i --){

    showDigit(digits[i-1], 100);

  }

  int sequence[] = {1, 3, 1, 4, 8, 8, 2, 0, 1};

  
  for(int i = 0; i < sizeof(sequence)/sizeof(sequence[0]); i ++){

    showDigit(digits[sequence[i]], 500);

  }
  
}

void showDigit(int digit[], int delayTime){
  
  for (int i = 0; i<8; i++){
    digitalWrite(segments[i], digit[i]);
  }  

  delay(delayTime);

  for (int i = 0; i<8; i++){
    digitalWrite(segments[i], HIGH);
  }

  delay(5);
}

