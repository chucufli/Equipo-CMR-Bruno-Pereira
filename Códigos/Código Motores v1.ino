int RuedaDerSupAdelante = 2;
int RuedaDerSupAtras = 3;
int RuedaIzqSupAdelante = 4;
int RuedaIzqSupAtras = 5;
int RuedaDerInfAdelante = 6;
int RuedaDerInfAtras = 7;
int RuedaIzqInfAdelante = 8;
int RuedaIzqInfAtras = 9;


void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  Adelante(2);
  Atras(2);
  Girar(0.5);
}
void Adelante(float segundos){ //Funcion utilizada para hacer girar los 4 motores en sentido horario
  
  digitalWrite(RuedaDerSupAdelante, LOW);
  digitalWrite(RuedaDerSupAtras, HIGH);
  digitalWrite(RuedaIzqSupAdelante , LOW);
  digitalWrite(RuedaIzqSupAtras, HIGH);
  digitalWrite(RuedaDerInfAdelante, LOW);
  digitalWrite(RuedaDerInfAtras, HIGH);
  digitalWrite(RuedaIzqInfAdelante , LOW);
  digitalWrite(RuedaIzqInfAtras, HIGH);
  delay(1000*segundos);
}
void Girar(float segundos){ //Funcion utilizada para hacer girar las ruedas del lado izquierdo en sentido horario,
   //y las del lado derecho en sentido antihorario, con tal de que el vehiculo realize un giro
  
  digitalWrite(RuedaDerSupAdelante, LOW);
  digitalWrite(RuedaDerSupAtras, HIGH);
  digitalWrite(RuedaIzqSupAdelante , LOW);
  digitalWrite(RuedaIzqSupAtras, HIGH);
  digitalWrite(RuedaDerInfAdelante, HIGH);
  digitalWrite(RuedaDerInfAtras, LOW);
  digitalWrite(RuedaIzqInfAdelante , HIGH);
  digitalWrite(RuedaIzqInfAtras, LOW);
  delay(1000*segundos);
}
void Atras(float segundos){ //Funcion utilizada para hacer girar los 4 motores en sentido antihorario
  
  digitalWrite(RuedaDerSupAdelante, HIGH);
  digitalWrite(RuedaDerSupAtras, LOW);
  digitalWrite(RuedaIzqSupAdelante , HIGH);
  digitalWrite(RuedaIzqSupAtras, LOW);
  digitalWrite(RuedaDerInfAdelante, HIGH);
  digitalWrite(RuedaDerInfAtras, LOW);
  digitalWrite(RuedaIzqInfAdelante , HIGH);
  digitalWrite(RuedaIzqInfAtras, LOW);
  delay(1000*segundos);
}