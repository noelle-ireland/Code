// digital pin 2 has a pushbutton attached to it. Give it a name:
int potent1 = A0;
int press1 = A2;
int led1 = 9;
int led2 = 10;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the potent, pressure an input:
  pinMode(potent1, INPUT);
  pinMode(press1, INPUT);
  // define LEDs as output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int potRead = analogRead(potent1);
  int pressRead = analogRead(press1);
  //electivity is flowing, set pin 3 to high
//  Serial.print("Potent= ");
//  Serial.print(potRead);
//  Serial.print(" Pressure= ");
//  Serial.println(pressRead);

  int potentNine = map(potRead, 0, 1023, 0, 255);
  analogWrite(led1, potentNine);
  Serial.print("led1= ");
  Serial.print(potentNine);

  int pressureTen = map(pressRead, 0, 1023, 0, 255);
  analogWrite(led2, pressureTen);
  Serial.print(" led2= ");
  Serial.println(pressureTen);
  
  // 0 1023 -> 0 255

//  if(buttonState == HIGH){
//    digitalWrite(3, HIGH);
//  }
//  //otherwise set pin 3 to low
//  else{
//    digitalWrite(3, LOW);
//  }
    
}
