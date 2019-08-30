/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int valFoto = 0;
int valPot = 0;
int porcPot = 0;
int porcFoto = 0;
int pot = A10;

// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(9600);
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  valFoto = analogRead(A2);
  valPot = analogRead(pot);
  porcPot = valPot*0.0976;
  porcFoto = valFoto*0.1149;
  Serial.print(valPot);
  Serial.print(" ");
  Serial.print(porcPot); 
  Serial.print("% ");
  Serial.print(valFoto);
  Serial.print(" ");
  Serial.print(porcFoto);
  Serial.println("%");
  
  if(valFoto > valPot){
    digitalWrite(led, HIGH);  
  }
  else{          
    digitalWrite(led, LOW);  
  }
}
