
#include <Wire.h>

int estado[] = {0,0};
int inPin1 = 6, inPin2 = 7;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(inPin1, INPUT);  // declare pushbutton as input
  pinMode(inPin2, INPUT);
}

void loop(){
  Wire.beginTransmission(1);
  estado[0] = digitalRead(inPin1);
  estado[1] = digitalRead(inPin2);
//estado = {digitalRead(inPin1), digitalRead(inPin2)};  // read input value
  Wire.write(estado[0]);
  Wire.write(estado[1]);
  Wire.endTransmission();
  Serial.print(estado[0]);
  Serial.println(estado[1]);
   
}
