#include <Arduino.h>

int x;
bool I1 = false;
bool I2 = false;
bool I3 = false;
bool I4 = false;
bool I5 = false;
bool I6 = false;
bool I7 = false;
bool I8 = false;

int del =20;

void setup() {
  
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() { 

 if(digitalRead(2)==0 && I1==false){
   Serial.print("I1=1");
    I1=true;
    delay(del);
    }else if(digitalRead(2)==1 && I1==true){
    Serial.print("I1=0");
    I1=false;
    delay(del);
    }
  
    if(digitalRead(3)==0 && I2==false){
   Serial.print("I2=1");
    I2=true;
    delay(del);
    }else if(digitalRead(3)==1 && I2==true){
    Serial.print("I2=0");
    I2=false;
    delay(del);
    }

    if(digitalRead(4)==0 && I3==false){
   Serial.print("I3=1");
    I3=true;
    delay(del);
   }else if(digitalRead(4)==1 && I3==true){
    Serial.print("I3=0");
    I3=false;
    delay(del);
   }

    if(digitalRead(5)==0 && I4==false){
   Serial.print("I4=1");
    I4=true;
    delay(del);
    }else if(digitalRead(5)==1 && I4==true){
    Serial.print("I4=0");
    I4=false;
    delay(del);
    }

    if(digitalRead(6)==0 && I5==false){
   Serial.print("I5=1");
    I5=true;
    delay(del);
    }else if(digitalRead(6)==1 && I5==true){
    Serial.print("I5=0");
    I5=false;
    delay(del);
   }

    if(digitalRead(7)==0 && I6==false){
   Serial.print("I6=1");
    I6=true;
    delay(del);
   }else if(digitalRead(7)==1 && I6==true){
    Serial.print("I6=0");
    I6=false;
    delay(del);
    }

    if(digitalRead(8)==0 && I7==false){
   Serial.print("I7=1");
    I7=true;
    delay(del);
    }else if(digitalRead(8)==1 && I7==true){
    Serial.print("I7=0");
    I7=false;
    delay(del);
   }

    if(digitalRead(9)==0 && I8==false){
   Serial.print("I8=1");
    I8=true;
    delay(del);
   }else if(digitalRead(9)==1 && I8==true){
    Serial.print("I8=0");
    I8=false;
    delay(del);
   }
 x=Serial.readString().toInt();
    if(x==1){digitalWrite(10,HIGH);} //Set Output 1 HIGH
    if(x==2){digitalWrite(10,LOW);}  //Set Output 1 LOW
    if(x==3){digitalWrite(11,HIGH);} //Set Output 2 HIGH
    if(x==4){digitalWrite(11,LOW);}  //Set Output 2 LOW
    if(x==5){digitalWrite(12,HIGH);} //Set Output 3 HIGH
    if(x==6){digitalWrite(12,LOW);}  //Set Output 3 LOW
    if(x==7){digitalWrite(13,HIGH);} //Set Output 4 HIGH
    if(x==8){digitalWrite(13,LOW);} //Set Output 4 LOW
    delay(del);}


  
  


  

  
   
  
