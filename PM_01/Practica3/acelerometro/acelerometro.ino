#include <Wire.h>

int estado[] = {0,0,0};
int aux = 0;
int valores = 0;


int xpin = A1;                  
int ypin = A2;                  
int zpin = A3;

float x = 0;
float y = 0;
float z = 0;

float refx = 0;
float refy = 0;
float refz = 0;
  
//int t_muestreo = 100;
void setup(){
  Serial.begin(9600);
  //Wire.begin();
  //analogReference(EXTERNAL);  
  
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(zpin, INPUT);
  refx = analogRead(xpin);
  refy = analogRead(ypin);
  refz = analogRead(zpin);
}

void loop()
{
 //Wire.beginTransmission(1);
 estado[0] = analogRead(xpin); 
 aux = (refx - estado[0]);
 if(aux < -15) {
  valores = 0;
 } else {
  if (aux > 15) {
    valores = 2;
  } else {
    valores = 1;
  }
 }
 
    delay(1);
 
 estado[1] = analogRead(ypin); 
 
    delay(1);
 
 estado[2] = analogRead(zpin);
 
//estado = {digitalRead(inPin1), digitalRead(inPin2)};  // read input value
  //Wire.write(valores);
  //Wire.endTransmission();
Serial.print(valores);
//  Serial.print(valores);
//  Serial.print("\t");
// 
//  Serial.print(refx - estado[0]);
//  Serial.print("\t");
// 
//  Serial.print(refy - estado[1]);
//  Serial.print("\t");
//  
//  Serial.println(refz - estado[2]);
 
  //delay(t_muestreo);
}
