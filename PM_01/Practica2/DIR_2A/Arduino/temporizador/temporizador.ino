
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int cont = 0;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
    cli();
    TCCR1B = 0; TCCR1A = 0;
    TCCR1B |= (1 << CS12);
    TCNT1 = 3036;
    TIMSK1 |= (1 << TOIE1);
    sei();
    DDRB =  DDRB | 0xff;
    DDRE =  DDRE | 0xff;
  }
  ISR(TIMER1_OVF_vect) {
    cont = (cont + 1 )%12;
    Serial.println(cont);
  }


// the loop routine runs over and over again forever:
void loop() {
  if(cont == 0){
   asm(
    "cbi 0x05,0x04 \n\t"
    "cbi 0x05,0x05 \n\t"
    "cbi 0x05,0x06 \n\t"
    "sbi 0x05,0x07 \n\t"
    "cbi 0x0e,0x03 \n\t"
    "sbi 0x0e,0x05 \n\t"
    ); 
  }
  if(cont == 5){
    asm(
    "sbi 0x05,0x06 \n\t"
    "cbi 0x05,0x07 \n\t"
    );
  }
  if(cont == 6){
    asm(
    "cbi 0x05,0x06 \n\t"
    "sbi 0x05,0x05 \n\t"
    "cbi 0x0e,0x05 \n\t"
    "sbi 0x05,0x04 \n\t"
    );
  }
  if(cont == 11){
    asm(
    "cbi 0x05,0x04 \n\t"
    "sbi 0x0e,0x03 \n\t"
    );
  }
  
}
