// Inicia as bibliotecas do Display LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// Inicia o Display LCD 16x2 através do endereço 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
// Define o pino de Leitura do Sensor
int sensorPin = A0;

int leitura; //Variável responsável por guardar o valor da leitura analógica do sensor
int calibra =1; //calibrar o valor para agua limpa


int pinlevel =7;// pin do nivel
 
void setup() {
  Serial.begin(9600); //Inicializa a comunicação serial
  // Inicia o display LCD
  lcd.init();
  lcd.backlight();
  pinMode (8, OUTPUT); //relé
  pinMode(pinlevel,INPUT); 
}
 
void loop() {

  leitura = analogRead(sensorPin); //Realiza a leitura analógica do sensor

  Serial.print("Valor lido: "); //Imprime no monitor serial
  Serial.println(leitura); // manda o valor de leitura para o monitor serial
  delay(500); //Intervalo de 0,5 segundos entre as leituras
  Serial.print("Estado da água: "); //Imprime no monitor serial

  //quanto mais proximo de 0 mais turva esta

  if (leitura > 700) { //Se o valor de leitura analógica estiver acima de 700
    Serial.println("LIMPA"); //Imprime no monitor serial que a água está limpa
    digitalWrite(8, LOW); //percentagem menor que 10 //rele
  }
  if ((leitura > 600) && (leitura <= 700)) { //Se o valor de leitura analógica estiver entre 600 e 700
    Serial.println("UM POUCO SUJA"); //Imprime no monitor serial que a água está um pouco suja
    digitalWrite(8, LOW); //percentagem menor que 10 //rele
  }
  if (leitura < 600) { //Se o valor de leitura analógica estiver abaixo de 600 
    Serial.println("MUITO SUJA"); //Imprime no monitor serial que a água está um pouco suja
    if (digitalRead(pinlevel)==HIGH){ //verificar nivel do tanque // se for low esta o deposito de agua suja cheio
    digitalWrite(8, HIGH); //percentagem maior que 10 //rele
    }
  else 
  digitalWrite(8, LOW);
}
  

  Serial.println();

  
  // Imprime as informações na tela do LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Leitura: ");
  lcd.print(leitura); 
  lcd.print(" N.T"); //rever
  
  // Imprime as informações na tela do LCD
  //meter em percentagem
  lcd.setCursor(0, 1);
  lcd.print("% turbidez: ");
  lcd.print(90-(leitura/10)-calibra);
  lcd.print(" %");
  delay(10);
  
}





