/*
  This is printer scanner board hack to use
  the RGB led for fun.

  Here is code for an arduino uno that will utulize the led
  on the printer scanner boards.

  shout out to Robson Couto who also did similar with an  arduino and
  sparked me to create this.
  find his blog here http://dragaosemchama.com

  Written by: brandon bodagous
  10-2016

*/

int LEDRED = 9;  //pin1 on rgb led
int LEDBLUE = 10;  //pin 2 on rbg led
int LEDGREEN = 11;  //pin 4 on rbg led

/*the third pin is gnd*/

void setup()
{
  pinMode(10, OUTPUT); 
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  for (int fadingLED = 0; fadingLED <= 255; fadingLED += 5) {  
    analogWrite(LEDRED, fadingLED);
    delay(45);
  }
//somewhat interesting results with the led. could be any number of things
  for (int fadingLED = 0; fadingLED <= 255; fadingLED += 5) {
    analogWrite(LEDBLUE, fadingLED);
    delay(45);
//play with the values. also thinking pwm? or ppm?
  }
  for (int fadingLED = 0; fadingLED <= 255; fadingLED += 5) {
    analogWrite(LEDGREEN, fadingLED);
    delay(45);
  }
}
