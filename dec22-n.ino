


unsigned long currentMS=0; 
unsigned long oldMS=0; 

//unsigned long myMs=0; 
//unsigned long myMsOld=0; 

//PUT YOUR VARIABLES HERE

void setup(){
    
    Spark.function("my-main", myMain);  
    

    //PUT YOUR SETUP CODE HERE. Note: Only three more functions allowed!
    // test everything using the return int from a function!
      
  
  RGB.control(true);
  RGB.color(0, 255, 255);  //cyan
  RGB.brightness(1);    // 1=very low light, 255 = max


}

void loop(){
    //PUT YOUR LOOP CODE HERE
    delay(20);    
    currentMS = millis();    
    
    
    if(currentMS > (oldMS + 10000)){     //  every 10 seconds
       oldMS = currentMS;                // reset timer
       RGB.color(0, 255, 255);           // cyan
       delay(200);
       RGB.color(0, 0, 0);               // off
       
       // do other stuff that needs to be done every 10 seconds
    }
      


}

int myMain(String myCode) {
    
    myCode.toUpperCase();           // set argument to uppercase--remove for better security
    
    //send as a variable
    //d7-send-1 or d7-send-high or d7-send-on    to turn on D7
    //d7-send-0   or d7-send-low  or d7-send-off to tuurn off D7


     
     
    // Block sets pinNumber for digital 0-7 or analog 10-17 from the number
    int mySetWrite = 0;
    int pinNumber = myCode.charAt(1) - '0';
    if (pinNumber< 0 || pinNumber >7) return -1; 
    if (myCode.startsWith("A")){pinNumber = pinNumber+10;}  //+10 is for analog numbers
    
    
  
    String  myActivity = myCode.substring(3,7);     // take 4 characters starting at the 3rd.
     
    
    //Following sets the 7 and on characters to integers
    String myOptional = myCode.substring(8);      
    if(myOptional == "HIGH") {mySetWrite = 1;}
        else if(myOptional == "LOW") {mySetWrite = 0; }
            else if(myOptional == "ON") {mySetWrite = 1;}
                else if(myOptional == "OFF") {mySetWrite = 0; }
                   else {mySetWrite = myOptional.toInt();  }  // sets  write value
    
    
    // code parsing complete
    
    
    if (pinNumber < 9) {   // digital pins activated
   
        if (myActivity == "READ"){    //digital read
            pinMode(pinNumber, INPUT_PULLDOWN);
            return digitalRead(pinNumber);
        }
        
        if (myActivity == "SEND"){    //digital write
            pinMode(pinNumber, OUTPUT);
            digitalWrite(pinNumber, mySetWrite);
            return mySetWrite;
        }        
        
        
        
    }  else {      // analog pins activated
    
        if (myActivity == "READ"){    //Analog read
            pinMode(pinNumber, INPUT);
            return analogRead(pinNumber);
        }
        
        if (myActivity == "SEND"){    //Analog Write
            pinMode(pinNumber, OUTPUT);
            analogWrite(pinNumber,  mySetWrite);
            return mySetWrite;
        }        
        
      }
    
    
    

    
}
