#include <rExcel.h> //please refer to link in LinkedIn post to Roberto Volgolio's website

rExcel myExcel; //called from library
char value[16]; //to catch PWM signal from Excel
char PWMV[16];  //to catch PWM signal from Excel
char T[3];      //to change rotor direction
int S;          ////to change rotor direction

const int IN3 = 7;  
const int IN4 = 6;
const int ENB = 3; //PWM control through this Pin

void setup() {   
  Serial.begin(9600);   //use Port COM3
  myExcel.clearInput();

  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENB, OUTPUT);
}

void loop() {
  
  myExcel.get("Example","B2",value); //this command uses libary to get value from excel
  int PWMV = atoi(value);
  analogWrite(ENB, PWMV); 

  myExcel.get("Example","B6",T);
  int S = atoi(T);
  myExcel.write("Example","B7",S);
  
  if (S==0)
  {
    digitalWrite(IN3, LOW); //this combination rotates rotor clockwise
    digitalWrite(IN4, HIGH);
  }
  else if (S!=0)
  {
    digitalWrite(IN3, HIGH); //this combination rotates rotor counter clockwise
    digitalWrite(IN4, LOW);    
  }
      
}
