

//PUT YOUR VARIABLES HERE

void setup()
{
    Spark.function("my-main", myMain);  // work here
    

    //PUT YOUR SETUP CODE HERE on three more functions allowed!
    // test everything using the return int from a function!
    


}

void loop()
{
    //PUT YOUR LOOP CODE HERE

}

int myMain(String myCode) {
    
    myCode.toUpperCase();           // set argument to uppercase--remove for better security
    
    //send as a variable
    //D7,DWR,1 or D7,DWR,HiGH    to turn on D7
    //D7,DWR,1 or D7,DWR,HiGH    to turn on D7
    //D7,DRE,1 or D7,DRE,HiGH    to read D7 returns 0 =off 1=on
    
    //A0,ARE  to read A0 returns a number between 0 and 4096
    //A0,AWR,255 to write A0 to maximum
     //A0,AWR,0 to write A0 to minimum = off 
     
     
    // Block sets pinNumber for digital 0-7 or analog 10-17 from the first 2 alphas D0,DWR,1
    int mySetWrite = 0;
    int pinNumber = myCode.charAt(1) - '0';
    if (pinNumber< 0 || pinNumber >7) return -1; 
    if (myCode.startsWith("A")){pinNumber = pinNumber+10;}  
    
    
  
    String  myActivity = myCode.substring(3,6);     // sets Choices from the 3-5 charachter D0,DRW,1
     
    
    //Following sets the 7 and on characters to integers
    String myOptional = myCode.substring(7);      
    if(myOptional == "HIGH") {mySetWrite = 1;}
        else if(myOptional == "LOW") {mySetWrite = 0; }
            else {mySetWrite = myOptional.toInt();  }  // sets  write value
    
    
    // code parsing complete
    
   
    if (myActivity == "DRE"){    //DRE = digital read
        pinMode(pinNumber, INPUT_PULLDOWN);
        return digitalRead(pinNumber);
    }
    
    
    if (myActivity == "DWR"){    //DWR = digital write
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, mySetWrite);
        return mySetWrite;
    }
    
    
    
    
    if (myActivity == "ARE"){    //DRE = Analog read
        pinMode(pinNumber, INPUT);
        return analogRead(pinNumber);
    }
    
    
    
    
    if (myActivity == "AWR"){    //DWR = Analog Write
        pinMode(pinNumber, OUTPUT);
        analogWrite(pinNumber,  mySetWrite);
        return mySetWrite;
    }
    
    
    
}
