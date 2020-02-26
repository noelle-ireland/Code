 
  // int variable to store sensorRead
  int sensorRead = "";
  // declare float for frequency value
  float frequ = 0.0;

  void setup() {
    // initialize serial communication  9600 bits/second:
    Serial.begin(9600);

    // define input/output
    pinMode(A0, INPUT);
    pinMode(9, OUTPUT);
  }

  void loop(){
    
    // read analog input A0, set sensorRead to this value
    sensorRead = analogRead(A0);
    // print to the serial monitor
    Serial.print(" A0 reading = ");
    Serial.print(sensorRead);

    // map sensorRead to a an output between 100 and 1000, set frequency to this
    int mapping = map(sensorRead, 100, 950, 100, 1000);
    // print it to the serial monitor
    Serial.print(" A0 mapped = ");
    Serial.println(mapping);
    tone(9, mapping);
    
    //change pitch, play 10ms - use tone()
  }
