int temp = 0;

void setup() {
  pinMode(D7, OUTPUT);
  pinMode(A0, INPUT);
  Spark.function("d7-on", d7On);
  Spark.function("d7-off", d7Off);
}

void loop() {
   // nothing here
}

int d7On(String args) {
  digitalWrite(D7, HIGH);
  return 1;
}

int d7Off(String args) {
  digitalWrite(D7, LOW);
  return 1;
}
