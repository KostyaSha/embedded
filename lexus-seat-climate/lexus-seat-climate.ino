
volatile int sensorValue1 = 350;      
volatile int sensorValue2 = 350;

void setup() {
}

void loop() {
  // read the analog in value:
  sensorValue1 = analogRead(A3);
  delay(50);
  sensorValue2 = analogRead(A2);
  //delay(50);
  
  sensorValue1 = constrain(sensorValue1, 390, 680); // limit borders for potentiometer position
  sensorValue2 = constrain(sensorValue2, 390, 680);
    
  // map it to the range of the analog out:
  sensorValue1 = map(sensorValue1, 390, 680, 0, 255);
  sensorValue2 = map(sensorValue2, 390, 680, 0, 255);
  
  // change the analog out value:
  analogWrite(0, sensorValue1);
 // delay(50);
  analogWrite(1, sensorValue2);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(20);
}
