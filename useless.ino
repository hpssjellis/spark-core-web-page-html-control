int temp = 0;

void setup() {
  pinMode(D7, OUTPUT);
  pinMode(A0, INPUT);
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
I call this useless since a spark device can only so far Dec, 2014 have 4 Spark.funcitons 
which means this program can do very little beyond turning on the LED

*/
