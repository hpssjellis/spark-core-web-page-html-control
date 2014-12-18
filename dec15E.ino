


int analogvalue = 0;
double tempC = 0.0;
char *message = "My name is spark";
unsigned long currentMS=0; 
unsigned long oldMS=0; 





void setup() {
  pinMode(D7, OUTPUT);  //set D7 to set the LED
  Spark.function("d7-on", d7On);
  Spark.function("d7-off", d7Off);
  
  
  RGB.control(true);
  RGB.color(0, 255, 255);  //cyan
  RGB.brightness(1);    // 1=very low light, 255 = max
  
  
  pinMode(A0, INPUT);   // set A0 for reading data
  Spark.variable("a0-read", &analogvalue, INT);
  Spark.variable("a0-temp", &tempC, DOUBLE);
  Spark.variable("mess", message, STRING);

  
  
}







void loop() {
    
    delay(20);    
    currentMS = millis();     
    double voltage = 0.0;
    
    
    if(currentMS > (oldMS + 2000)){     //  update every 2 seconds

        analogvalue = analogRead(A0);
        voltage = (analogvalue * 3.3) / 4095;  // convert reading to voltage
        tempC  = (voltage - 0.5) * 100;     //Convert the reading into degree celcius
    
    }

    
    
    if(currentMS > (oldMS + 10000)){     //  every 10 seconds
       oldMS = currentMS;              // reset timer
       RGB.color(0, 255, 255);
       delay(200);
       RGB.color(0, 0, 0);
    }
    

    
} //   end main loop




int d7On(String args) {
  digitalWrite(D7, HIGH);
  return 1;
}

int d7Off(String args) {
  digitalWrite(D7, LOW);
  return 0;
}


