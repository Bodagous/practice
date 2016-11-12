
/*

  practicing use of swtich statements

  everybody standclear i dont know what im doing

  want/needs

  want to turn servo from serial commands

  written by: brandon

*/

#include <Servo.h>  // ehhh


Servo dervo;

void setup()
{
  Serial.begin(115200);
  dervo.attach(9);  // servo input pin
}

void loop()
{
  if (dervo.read() != 0);
  Serial.println("if something pops before this its current servo position");  {
    int letsroll = Serial.read();
    switch (letsroll) {
      case 'a':
        dervo.write(90);
        Serial.println("servo moves 90");
        delay(100);// do something
        break;
      case 'b':
        dervo.write(45);
        Serial.println("servo moves 45");
        delay(100);// do something
        break;
    }
  }
}