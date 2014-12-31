

void setup() {
  pinMode(D7, OUTPUT);
  Spark.function("myTurnOn", turnOn);
  Spark.function("myTurnOff", turnOff);
}

void loop() {
   // nothing here
}

int turnOn(String args) {
  digitalWrite(D7, HIGH);
  return 1;
}

int turnOff(String args) {
  digitalWrite(D7, LOW);
  return 1;
}



/*


I call this useless.ino because the spark devices as of dec 2014 only allow 4 spark.functions
meaning this program can not do much more than this.



*/
