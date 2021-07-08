#include <LiquidCrystal.h>
int in = A1;
int inpr = A3;
int out = A0;
int outpr = A2;
int ppl = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
bool pi = 0;
bool po = 0;
bool pipr=0;
bool popr=0;
bool lo=0;
bool ro=0;
bool li=0;
bool ri=0;
void setup() {
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  pi = digitalRead(in);
  pipr = digitalRead(inpr);
  po = digitalRead(out);
  popr = digitalRead(outpr);
  if (pi == 1){
    if(ri==1){
    ppl++;
    ri=0;
    }else
    li=1;
    delay(500);
  }
  else if (pipr == 1){
   if(li==1){
    ppl-- ;
     li=0;
   }else
   ri=1;
    delay(500);
  }
  else if (po == 1){
    if(ro==1){
    ppl-- ;
      ro=0;
    }else
      lo=1;
    delay(500);
  }
else if (popr == 1){
  if(lo==1){
    ppl++ ;
    lo=0;
  }else
    ro=1;
    delay(500);
  }
  ppl = constrain(ppl, 0, 50);
  lcd.setCursor(0, 0);
  lcd.print("PEOPLE IN:");
  lcd.setCursor(11, 0);
  lcd.print(ppl);
  if (ppl >= 20){
     lcd.setCursor(0, 1);
     lcd.print("PLEASE WAIT");
     delay(1000);
  }
  if (ppl <= 19){
     lcd.setCursor(0, 1);
     lcd.print("PLEASE VISIT");
     delay(1000);
  }
}