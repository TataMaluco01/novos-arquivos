// versão teste 1a
int leda=13;      // led no pino 13
int ledb=11;      // led no pino 13
int botao=12;  // botão no pino 12
int ledred=10; //led RGB
int ledgreen=9; //led RGB
int ledblue=8; //led RGB
int var=0;       // valor instantaneo enviado pelo botão
int var2=0;     // valor guardado
int estado=0;  // guarda o valor 0 ou 1 (HIGH ou LOW)
void setup()
{
  pinMode(leda,OUTPUT);  // off leds_power
  pinMode(ledb,OUTPUT);  // on leds_power
  pinMode(botao,INPUT);  //change estado
}
/*while (condição) {
  // código a ser executado repetidamente
}*/
void RGB()
{
  digitalWrite(ledred, HIGH); // liga RED
  digitalWrite(ledgreen, LOW); // desliga GREEN
  digitalWrite(ledblue, LOW); // desliga BLUE
  delay(1000);
  digitalWrite(ledred, LOW); // desliga RED
  digitalWrite(ledgreen, HIGH); // liga GREEN
  digitalWrite(ledblue, LOW); // desliga BLUE 
  delay(1000);
  digitalWrite(ledred, LOW); // desliga RED
  digitalWrite(ledgreen, LOW); // desliga GREEN
  digitalWrite(ledblue, HIGH); // liga BLUE
  delay(1000);
}
void noRGB()
{
  digitalWrite(ledred, LOW); // liga RED
  digitalWrite(ledgreen, LOW); // desliga GREEN
  digitalWrite(ledblue, LOW); // desliga BLUE
  }
void loop()
{
  var=digitalRead(botao); // ler o valor enviado pelo botão: "HIGH" ou "LOW"
  if ((var == HIGH) && (var2 == LOW)) {
    estado = 1 - estado;
    delay(200); // de-bouncing
  }
  var2=var;
  if (estado == 1) {
    digitalWrite(leda, HIGH); // liga verde
    digitalWrite(ledb, LOW); // desliga vermelho
    delay(500);
    RGB();
  } 
  else 
  {
    digitalWrite(leda, LOW);  // desliga verde 
    digitalWrite(ledb, HIGH);  // liga vermelho
    noRGB();
  }
}
