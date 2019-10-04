int val = 0;

int xpin = A1;                  
int ypin = A2;                  
int zpin = A3;                
 
int t_muestreo = 500;   // Tiempo de muestreo del acelerómetro
void setup()
{
 Serial.begin(9600);
  analogReference(EXTERNAL);  // La tensión aplicada en el pin AREF (3.3V) será la que haga que el conversor analogo-digital
                              // de su máxima lectura (1023) 
    
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(zpin, INPUT);
}

void loop()
{
 int x = analogRead(xpin); // Leemos el valor de la tensión en el pin x
 
    delay(1); // Esperamos 1 ms a leer en el próximo pin
 
  int y = analogRead(ypin); // Leemos el valor de la tensión en el pin y
 
    delay(1); // Esperamos 1 ms a leer en el próximo pin
 
  int z = analogRead(zpin);
 
  float zero_G = 512.0;
 
  float escala = 102.3;
 
  Serial.print(((float)x - zero_G)/escala);
  Serial.print("\t");
 
  Serial.print(((float)y - zero_G)/escala);
  Serial.print("\t");
 
  Serial.print(((float)z - zero_G)/escala);
  Serial.print("\n");
 
  // delay entre cada lectura
  delay(t_muestreo);
}
