/*    

This file is called useless.ino not because it does not work but because it uses up 
all four of your allowable spark.funcitons so that you can't include anymore functions

If you only wanted to do 4 things then this is fine. Possibly the easiest way to do most spark functions.

Note: digital read example below but we do not have enough spark.functions available to activate it

*/





//PUT YOUR VARIABLES HERE

void setup(){
    
  
    Spark.function("d7-send-on", d7SendOn);
    Spark.function("d7-send-off", d7SendOff);
    
    Spark.function("a0-send", a0Send);
    Spark.function("a1-read", a1Read);




   // Spark.function("d6-read", d6Read);
   
   //PUT YOUR SETUP CODE HERE

}

void loop(){
    //PUT YOUR LOOP CODE HERE

}




int d7SendOn(String myCommand){
    pinMode(D7, OUTPUT);     // output means information out of the spark device
    digitalWrite(D7, HIGH);  // send 1 high 0 low
    return 1;
}
    

int d7SendOff(String myCommand){
    pinMode(D7, OUTPUT);
    digitalWrite(D7, LOW);  // send 1 high 0 low
    return 0;
}
   
   
// int d6Read(String myCommand){ // digital read example 
//     pinMode(D6, OUTPUT);    
//     return digitalRead(D6);   
// }



int a1Read(String myCommand){
    pinMode(A1, INPUT);    // input means information into the spark device
    return analogRead(A1);   
}


int a0Send(String myCommand){      // the only function that actuall uses myCommand
    pinMode(A0, OUTPUT);
    analogWrite(A0, myCommand.toInt());  // send a number between 255 High and 0 low and any in between
    return myCommand.toInt();
}
   
   

   
   
