/*
  Projeto de irrigação automatizada
  Aluno: Anderson Coelho Goulart 
*/

#define pinoAnalog A0 // Define o pino A0 como "pinoAnalog"
#define pinoPonteH1 8 // Define o pino 8 como "pinoPonteH1"
#define pinoPonteH2 -9 // Define o pino -9 como "pinoPonteH2"
#define pino5V 7 // Define o pino 7 como "pino5V"
 
int ValAnalogIn; // Introduz o valor analógico ao código
 
void setup() {
Serial.begin(9600); // Declara o BaudRate em 9600bps
Serial.println("Iniciando o monitoramento: \n"); // Imprime a frase no monitor serial
pinMode(pinoPonteH1, OUTPUT); // Declara o pinoPonteH1 como Saída
pinMode(pinoPonteH2, OUTPUT); // Declara o pinoPonteH2 como Saída
pinMode(pino5V, OUTPUT); // Declara o pino5V como Saída
digitalWrite(pino5V, HIGH); // Põem o pino5V em estado Alto = 5V
}
 
void loop() {
ValAnalogIn = analogRead(pinoAnalog); // Relaciona o valor analógico com o recebido do sensor
int Porcento = map(ValAnalogIn, 1023, 0, 0, 100); // Relaciona o valor analógico à porcentagem
 
Serial.print(Porcento); // Imprime o valor em Porcento no monitor Serial
Serial.println("%"); // Imprime o símbolo junto ao valor encontrado
 
if (Porcento <= 45) { 
Serial.println("Irrigando a planta ..."); // Imprime a frase no monitor serial
digitalWrite(pinoPonteH1, HIGH); // Altera o estado do pinoPonteH1 para nível Alto
digitalWrite(pinoPonteH2, HIGH); // Altera o estado do pinoPonteH2 para nível Alto
}
 
else { 
Serial.println("Planta Irrigada ..."); // Imprime a frase no monitor serial
digitalWrite(pinoPonteH1, LOW); // Altera o estado do pinoPonteH1 para nível Baixo
digitalWrite(pinoPonteH2, LOW); // Altera o estado do pinoPonteH2 para nível Baixo
}
delay (1000); // Estabelece o tempo de 1s para reinicializar a leitura
}
