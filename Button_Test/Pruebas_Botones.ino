
void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP);
  pinMode(10, OUTPUT);
}

void loop() {

  int sensorVal = digitalRead(4);

  Serial.println(sensorVal);

  if (sensorVal == HIGH) {
    digitalWrite(10, LOW);
  } else {
    digitalWrite(10, HIGH);
  }
}

