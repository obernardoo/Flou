// Flou 0.4


#include <Servo.h> 
 
Servo servo01;  // Servo  Compuertas  90
Servo servo02;  // Servo  Compuertas  90
Servo servo03;  // Servo  Tapones     180
Servo servo04;  // Servo  Tapones     180

int pinBoton01 = 2;    // Boton Frio/Calor
int pinBoton02 = 3;    // Boton Dia/Noche
int ledRojo = 4;       // LED Rojo Calor
int ledAzul = 5;       // LED Azul Frio
int pinVenti = 13;      // Ventilación

int selectCaso01 = 0;  // Select Frio/Calor
int numeroCasos01 = 2; // 0 = Frio 1 = Calor
int state01 = LOW;
int lastState01 = LOW;

int selectCaso02 = 0;  // Select Dia/Noche
int numeroCasos02 = 2; // 0 = Dia 1 = Noche
int state02 = LOW;
int lastState02 = LOW;


void setup() {  
  
 // Serial.begin(9600);
  
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(pinVenti, OUTPUT);
  pinMode(pinBoton01, INPUT);
  pinMode(pinBoton02, INPUT);
  
  servo01.attach(8);
  servo02.attach(9);
  servo03.attach(10);
  servo04.attach(11);
  
  state01 = digitalRead(pinBoton01);
  state02 = digitalRead(pinBoton02);
    
  selectCaso01 = 0;
  selectCaso02 = 0;
  
  servo01.write(40);
  servo02.write(40);
  servo03.write(0);
  servo04.write(0);
  
} 
 
 
void loop(){ 
  
  // Select Frio / Calor
  if (state01==HIGH && lastState01==LOW) {         
    selectCaso01 = (selectCaso01 + 1) % numeroCasos01;
     }   
  
  // Select Dia / Noche
  if (state02==HIGH && lastState02==LOW) {         
  selectCaso02 = (selectCaso02 + 1) % numeroCasos02;
   }
     
    // attach de nuevo los servos 
  if (state01==HIGH && lastState01==LOW || state02==HIGH && lastState02==LOW) {         
  
  servo01.attach(8);
  servo03.attach(9);
  servo02.attach(10);
  servo04.attach(11);
     }  
     
   
  if (selectCaso01 == 0) {           // CALOR        
    
    //Serial.print("Calor :: ");
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledAzul, LOW);
    
       if (selectCaso02 == 0) {        // DIA
     //    Serial.println("Dia");
         digitalWrite(pinVenti, HIGH);
         servo01.write(150);  // 90
         servo02.write(150);  // 90
         servo03.write(0);
         servo04.write(0);
          delay(500);
         servo01.detach();
         servo02.detach();
         servo03.detach();
         servo04.detach();

       }
       
       else {                          // NOCHE
      //   Serial.println("Noche");   
         digitalWrite(pinVenti, LOW);
         servo01.write(40);  // 0
         servo02.write(40);  // 0
         servo03.write(0);
         servo04.write(0);
          delay(500);
         servo01.detach();
         servo02.detach();
         servo03.detach();
         servo04.detach();
       }
     }  
     
  if (selectCaso01 == 1) {           // FRIO       
    
  //  Serial.print("Frio :: ");
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledRojo, LOW);
   
       if (selectCaso02 == 0) {        // DIA
   //      Serial.println("Dia");
         digitalWrite(pinVenti, LOW);
         servo01.write(40);  // 0
         servo02.write(40);  // 0
         servo03.write(180);
         servo04.write(180);
          delay(500);
         servo01.detach();
         servo02.detach();
         servo03.detach();
         servo04.detach();
    
       }
       
       else {
    //     Serial.println("Noche");     // NOCHE
         digitalWrite(pinVenti, LOW);
         servo01.write(150);  // 90
         servo02.write(150);  // 90
         servo03.write(180);
         servo04.write(180);
          delay(500);
         servo01.detach();
         servo02.detach();
         servo03.detach();
         servo04.detach();
       }
     }  
     
 delay(100);
   
 lastState01 = state01;
 state01 = digitalRead(pinBoton01);

 lastState02 = state02;
 state02 = digitalRead(pinBoton02);
    
 }   
                         
 
