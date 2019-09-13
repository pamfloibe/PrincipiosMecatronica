
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int button = 12;
int valBut = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  DDRB =  DDRB | B11111101;
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
    
  valBut = analogread(button);
  seria
  
  
  asm volatile(
    "inicio: \n\t" 
    "sbi 0x05,0x07 \n\t"
    
    
    
    
    "tiempo: \n\t"
    "LDI r22, 75 \n\t"
    "LOOP_3: \n\t"
    "LDI r21, 253 \n\t"
    "LOOP_2: \n\t"
    "LDI r20, 255 \n\t"
    "LOOP_1: \n\t"
    "DEC r20 \n\t"
    "BRNE LOOP_1 \n\t"
    "DEC r21 \n\t"
    "BRNE LOOP_2 \n\t"
    "DEC r22 \n\t"
    "BRNE LOOP_3 \n\t"
    "ret \n\t"
  );
  
}
