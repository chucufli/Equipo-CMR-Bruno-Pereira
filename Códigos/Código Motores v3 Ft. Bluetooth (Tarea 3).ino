#include <SoftwareSerial.h>
SoftwareSerial SerialBT(10, 11);


int RuedaDerSupAdelante = 2;
int RuedaDerSupAtras = 3;
int RuedaIzqSupAdelante = 4;
int RuedaIzqSupAtras = 5;
int RuedaDerInfAdelante = 6;
int RuedaDerInfAtras = 7;
int RuedaIzqInfAdelante = 8;
int RuedaIzqInfAtras = 9;
char a;


void setup()

{
  Serial.begin(9600);
  delay(1000);
  Serial.println("----");
  Serial.println("READY");
  Serial.println("----");
  delay(200);
  SerialBT.begin(9600);


  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {

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

  digitalWrite(RuedaDerSupAdelante, LOW);
  digitalWrite(RuedaDerSupAtras, HIGH);
  digitalWrite(RuedaIzqSupAdelante , LOW);
  digitalWrite(RuedaIzqSupAtras, HIGH);
  digitalWrite(RuedaDerInfAdelante, LOW);
  digitalWrite(RuedaDerInfAtras, HIGH);
  digitalWrite(RuedaIzqInfAdelante , LOW);
  digitalWrite(RuedaIzqInfAtras, HIGH);
  delay(1000*0.00005);
}
void Girar() {  // DERECHA,Funcion utilizada para hacer girar las ruedas del lado izquierdo en sentido horario,
                            //y las del lado derecho en sentido antihorario, con tal de que el vehiculo realize un giro

  digitalWrite(RuedaDerSupAdelante, HIGH);
  digitalWrite(RuedaDerSupAtras, LOW);
  digitalWrite(RuedaIzqSupAdelante, LOW);
  digitalWrite(RuedaIzqSupAtras, HIGH);
  digitalWrite(RuedaDerInfAdelante, LOW);
  digitalWrite(RuedaDerInfAtras, HIGH);
  digitalWrite(RuedaIzqInfAdelante, HIGH);
  digitalWrite(RuedaIzqInfAtras, LOW);
  delay(1000*0.00005);
}
void Atras() {  //Funcion utilizada para hacer girar los 4 motores en sentido antihorario

  digitalWrite(RuedaDerSupAdelante, HIGH);
  digitalWrite(RuedaDerSupAtras, LOW);
  digitalWrite(RuedaIzqSupAdelante, HIGH);
  digitalWrite(RuedaIzqSupAtras, LOW);
  digitalWrite(RuedaDerInfAdelante, HIGH);
  digitalWrite(RuedaDerInfAtras, LOW);
  digitalWrite(RuedaIzqInfAdelante, HIGH);
  digitalWrite(RuedaIzqInfAtras, LOW);
  delay(1000*0.00005);
}
void Girar2() {  //IzquierdaFuncion utilizada para hacer girar las ruedas del lado izquierdo en sentido horario,
                             //y las del lado derecho en sentido antihorario, con tal de que el vehiculo realize un giro

digitalWrite(RuedaDerSupAdelante, LOW);
  digitalWrite(RuedaDerSupAtras, HIGH);
  digitalWrite(RuedaIzqSupAdelante, HIGH);
  digitalWrite(RuedaIzqSupAtras, LOW);
  digitalWrite(RuedaDerInfAdelante, HIGH);
  digitalWrite(RuedaDerInfAtras, LOW);
  digitalWrite(RuedaIzqInfAdelante, LOW);
  digitalWrite(RuedaIzqInfAtras, HIGH);
  delay(1000*0.00005);
}

void Stop() {
  digitalWrite(RuedaDerSupAdelante, LOW);
  digitalWrite(RuedaDerSupAtras, LOW);
  digitalWrite(RuedaIzqSupAdelante, LOW);
  digitalWrite(RuedaIzqSupAtras, LOW);
  digitalWrite(RuedaDerInfAdelante, LOW);
  digitalWrite(RuedaDerInfAtras, LOW);
  digitalWrite(RuedaIzqInfAdelante, LOW);
  digitalWrite(RuedaIzqInfAtras, LOW);
}

char leerSerial() {
  SerialBT.listen();
  if (SerialBT.available() > 0) {
    a = SerialBT.read();
    Serial.println(a);
  }
  return a;
}
