unsigned long tiempo;
int ButtonA = 7;
int ButtonB = 6;
int ButtonC = 5;
int ButtonD = 4;

int espera = 200;                   //Valor de 200ms
int VRX = A1;                       //Lecturas tomadas del Joystick X
int VRY = A0;                       //Lecturas tomadas del Joystick Y


void setup() {
  Serial.begin(9600);
  pinMode(ButtonA, INPUT_PULLUP);   //Button A
  pinMode(ButtonB, INPUT_PULLUP);   //Button B
  pinMode(ButtonC, INPUT_PULLUP);   //Button C
  pinMode(ButtonD, INPUT_PULLUP);   //Button D

  //pinMode(3, INPUT);                //Button RST
  

  pinMode(8, OUTPUT);               //Motor A
  pinMode(9, OUTPUT);               //Motor B
  pinMode(10, OUTPUT);               //Motor C
  pinMode(11, OUTPUT);               //Motor D
  
}
void loop() {
    
  if(digitalRead(ButtonA) == HIGH && (millis() - tiempo) < espera 
                                  || analogRead(VRY) < 1023 && analogRead(VRY) > 800){         //Direccionando a la derecha
    for(int i = 0; i < 2; i++){
      digitalWrite(8, HIGH);
      delay(800);
      digitalWrite(8, LOW);  
      delay(200);
      digitalWrite(8, HIGH);
      delay(800);
      digitalWrite(8, LOW);  
      delay(500);
    }
  }
    
  if(digitalRead(ButtonB)== HIGH && (millis() - tiempo) < espera 
                                  || analogRead(VRX) > 0 && analogRead(VRX) < 250){         //Direccionando abajo
    for(int i = 0; i < 2; i++){
      digitalWrite(9, HIGH);
      delay(800);
      digitalWrite(9, LOW);  
      delay(200);
      digitalWrite(9, HIGH);
      delay(800);
      digitalWrite(9, LOW);  
      delay(500);
    }
  }
       
  if(digitalRead(ButtonC)== HIGH && (millis() - tiempo) < espera 
                                || analogRead(VRY) > 0 && analogRead(VRY) < 250){         //Direccionando a la izquierda
    for(int i = 0; i < 2; i++){
      digitalWrite(10, HIGH);
      delay(800);
      digitalWrite(10, LOW);  
      delay(200);
      digitalWrite(10, HIGH);
      delay(800);
      digitalWrite(10, LOW);  
      delay(500);
    }
  }
                          
  if(digitalRead(ButtonD) == HIGH && (millis() - tiempo) < espera 
                                  || analogRead(VRX) < 1020 && analogRead(VRX) > 800){         //Direccionando advertencia
    for(int i=0; i < 2; i++){
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      delay(500);
  
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(200);
  
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      delay(1000);
  
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(200);
    }
  }  
  tiempo = millis();
  
//  Serial.print("Lecturas del eje X");
//  Serial.print("\n");
//  Serial.print(analogRead(VRX));
//  delay(500);
//  Serial.print("\n");
//  
//  Serial.print("Lecturas del eje Y");
//  Serial.print("\n");
//  Serial.println(analogRead(VRY));
//  delay(500);
//  Serial.print("\n");

  
}
