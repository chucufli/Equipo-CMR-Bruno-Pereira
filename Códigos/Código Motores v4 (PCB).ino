#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial SerialBT(3, 2);

char a;
int RuedaDerAdelante = 8;
int RuedaDerAtras = 10;
int RuedaIzqAdelante = 11;
int RuedaIzqAtras = 12;

// Declaramos la variable para controlar el servo
Servo servoMotor;

Servo servoMotor1;


void setup()

{
  Serial.begin(9600);
  delay(1000);
  Serial.println("----");
  Serial.println("READY");
  Serial.println("----");
  delay(200);
  SerialBT.begin(9600);


  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  servoMotor.attach(6);

  servoMotor1.attach(9);
}

void loop() {

  //SERVO
  // Desplazamos a la posición 0º
  servoMotor.write(0);
  servoMotor1.write(0);

  // Esperamos 1 segundo
  delay(1000);

  // Desplazamos a la posición 180º
  servoMotor.write(100);
  servoMotor1.write(100);

  // Esperamos 1 segundo
  delay(1000);

  a = leerSerial();
  if (a == 'F') {
    Adelante();
  }
  if (a == 'R')
  {
    Girar();
  }
  if (a == 'L')
  {
    Girar2();
  }
  if (a == 'B')
  {
    Atras();
  }
  if (a == 'S')
  {
    Stop();
  }

  //Adelante(2);
  //Atras(2);
  //Girar(1);
}



void Adelante() {  //Funcion utilizada para hacer girar los 4 motores en sentido horario

  digitalWrite(RuedaDerAdelante, HIGH);
  digitalWrite(RuedaDerAtras, LOW);
  digitalWrite(RuedaIzqAdelante, HIGH);
  digitalWrite(RuedaIzqAtras, LOW);
  delay(1000*0.00005);
}
void Girar() {  // DERECHA,Funcion utilizada para hacer girar las ruedas del lado izquierdo en sentido horario,
                //y las del lado derecho en sentido antihorario, con tal de que el vehiculo realize un giro

  digitalWrite(RuedaDerAdelante, HIGH);
  digitalWrite(RuedaDerAtras, LOW);
  digitalWrite(RuedaIzqAdelante, LOW);
  digitalWrite(RuedaIzqAtras, HIGH);
  delay(1000*0.00005);
}
void Atras() {  //Funcion utilizada para hacer girar los 4 motores en sentido antihorario

  Stop();
  digitalWrite(RuedaDerAdelante, LOW);
  digitalWrite(RuedaDerAtras, HIGH);
  digitalWrite(RuedaIzqAdelante, LOW);
  digitalWrite(RuedaIzqAtras, HIGH);
  delay(1000*0.00005);
}
void Girar2() {  //IzquierdaFuncion utilizada para hacer girar las ruedas del lado izquierdo en sentido horario,
                 //y las del lado derecho en sentido antihorario, con tal de que el vehiculo realize un giro

  digitalWrite(RuedaDerAdelante, LOW);
  digitalWrite(RuedaDerAtras, HIGH);
  digitalWrite(RuedaIzqAdelante, HIGH);
  digitalWrite(RuedaIzqAtras, LOW);
  delay(1000*0.00005);
}

void Stop() {
  digitalWrite(RuedaDerAdelante, LOW);
  digitalWrite(RuedaDerAtras, LOW);
  digitalWrite(RuedaIzqAdelante, LOW);
  digitalWrite(RuedaIzqAtras, LOW);
}

char leerSerial() {
  SerialBT.listen();
  if (SerialBT.available() > 0) {
    a = SerialBT.read();
    Serial.println(a);
  }
  return a;
}

