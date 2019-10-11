#include <Wire.h>

int estado[] = {0,0,0};

int xpin = A1;                  
int ypin = A2;                  
int zpin = A3;

float x = 0;
float y = 0;
float z = 0;
  
//int t_muestreo = 100;
void setup()
{
 Serial.begin(9600);
  analogReference(EXTERNAL);  
  
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(zpin, INPUT);
}

void loop()
{
 Wire.beginTransmission(1);
 estado[0] = analogRead(xpin); 
 
    delay(1);
 
 estado[1] = analogRead(ypin); 
 
    delay(1);
 
 estado[2] = analogRead(zpin);
 
//estado = {digitalRead(inPin1), digitalRead(inPin2)};  // read input value
  Wire.write(estado[0]);
  Wire.endTransmission();
 
  Serial.print(estado[0]);
  Serial.print("\t");
 
  Serial.print(estado[1]);
  Serial.print("\t");
  
  Serial.println(estado[2]);
 
  //delay(t_muestreo);
}
