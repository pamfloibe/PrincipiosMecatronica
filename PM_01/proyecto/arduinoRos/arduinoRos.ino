//Contador esquinas
int esq = 0;

// Delay (distancia)
int delayD = 2400;

// Delay giro
int delayG = 280;

// Motor A
int ENA = 9;
int IN1 = 7;
int IN2 = 6;

// Motor B
int ENB = 8;
int IN3 = 5;
int IN4 = 4;

int vel = 150;

void setup()
{
 Serial.begin(9600) ;
 // Declaramos todos los pines como salidas
 pinMode (ENA, OUTPUT);
 pinMode (ENB, OUTPUT);
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
}

void loop()
{
  delay(6000);
  while(esq < 4){
    Adelante(); //recta1
    delay(delayD);
    Alto();
    delay(200);
    Derecha();
    delay(delayG);
    Alto();
    delay(200);
    esq++;
  }
   esq = 0;
  

  delay(1500);
  Circulo();
  delay(7100);
  Alto();
  
}

void Derecha ()
{
 //Direccion motor A
 digitalWrite (IN2, LOW);
 digitalWrite (IN1, HIGH);
 analogWrite (ENA, vel-10); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN4, LOW);
 digitalWrite (IN3, HIGH);
 analogWrite (ENB, vel-10); //Velocidad motor B
}

void Circulo ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, vel); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, vel - 40); //Velocidad motor A
}

void Adelante ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, vel); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, vel+20); //Velocidad motor A
} 


void Alto ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 0); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 0); //Velocidad motor B
}
