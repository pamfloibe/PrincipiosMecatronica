
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  DDRB =  DDRB | 0xff;
  DDRE =  DDRE | 0xff;
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
    
  asm volatile(
    "inicio: \n\t" 
    "cbi 0x05,0x04 \n\t"
    "cbi 0x05,0x05 \n\t"
    "cbi 0x05,0x06 \n\t"
    "sbi 0x05,0x07 \n\t"
    "cbi 0x0e,0x03 \n\t"
    "sbi 0x0e,0x05 \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "sbi 0x05,0x06 \n\t"
    "cbi 0x05,0x07 \n\t"
    "call tiempo \n\t"
    "sbi 0x05,0x05 \n\t"
    "cbi 0x05,0x06 \n\t"
    "cbi 0x0e,0x05 \n\t"
    "sbi 0x05,0x04 \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "sbi 0x0e,0x03 \n\t"
    "cbi 0x05,0x04 \n\t"
    "call tiempo \n\t"
    "jmp inicio \n\t" 
    
    
    
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
