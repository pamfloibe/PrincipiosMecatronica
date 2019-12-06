#include <ros.h>
#include <geometry_msgs/Pose2D.h>
#include <std_msgs/Int16.h>

ros::NodeHandle nh;

#include <PID_v1.h>

#define PI 3.1415926535897932384626433832795

const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

unsigned long tiempoVueltaDer = 0;
unsigned long contadorDer = 0;
int inicioDer = 0;

double velocidadAngular = 0;


//Define Variables we'll be connecting to
double velocidadNorma, entregaVelocidadDer;

//Specify the links and initial tuning parameters
PID myPID(&velocidadAngular, &entregaVelocidadDer, &velocidadNorma,0,8,2,P_ON_M, DIRECT); //P_ON_M specifies that Proportional on Measurement be used


void freqCallBack(const std_msgs::Int16& val){
  digitalWrite(13, val.data);
}

ros::Subscriber<std_msgs::Int16> blinker("freq1", freqCallBack );

void setup() {

  nh.initNode();
  nh.subscribe(blinker);

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);

  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  
  // Set initial rotation direction
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);

  velocidadNorma = 30;
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
  attachInterrupt(digitalPinToInterrupt(interruptPin), cuentaRPMDer, HIGH);
}

void loop() {
//  digitalWrite(ledPin, state);
  myPID.Compute();
  analogWrite(9, entregaVelocidadDer);
}

void cuentaRPMDer() {
  cli();
//  state = !state;
  if (inicioDer == 0) {
    inicioDer = 1;
    tiempoVueltaDer = millis();
  } else {
    contadorDer = millis();
    tiempoVueltaDer = contadorDer - tiempoVueltaDer;
    tiempoVueltaDer = tiempoVueltaDer * 20; // tiempo en dar una vuelta completa en ms
    velocidadAngular = (2000 * PI) / tiempoVueltaDer; // velocidad angular en rad/s
    inicioDer = 0;
  }
  
  sei();
}
