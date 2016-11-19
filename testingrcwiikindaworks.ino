/* this is just a small test for arduino to tx2 ic on the wii rc controller*/

int k1 = 5;  //foward
int k2 = 6;  //backward 
int k3 = 9;  //  right
int k4 = 10;  // left
int refreshTime = 200;
int w1 = 0;
int w2 = 0;
int startpulse = 100;
int functionpulse = 500;

void setup()
{
  pinMode(k1, OUTPUT);
  pinMode(k2, OUTPUT);
  pinMode(k3, OUTPUT);
  pinMode(k4, OUTPUT);
  w1 = startpulse;
  w2 = functionpulse;
}
void loop()
{
val = analogRead(inPin); // read the input pin
volt =(3.0 * val) / 1023;
val = 255 * (volt / 3);
analogWrite(k1, val);
  digitalWrite(k1, !digitalRead(k1));  // toggle state
  delayMicroseconds(w1);
  digitalWrite(k1, !digitalRead(k1));  // toggle state
  delayMicroseconds(w2);
}

void upnleft()
{
  digitalWrite(k1, !digitalRead(k1));  // toggle state
  digitalWrite(k4, !digitalRead(k4));  // toggle state
}

void upnright()
{
  digitalWrite(k1, !digitalRead(k1));  // toggle state
  digitalWrite(k3, !digitalRead(k3));
}

void downnleft()
{
  digitalWrite(k2, !digitalRead(k2));
  digitalWrite(k3, !digitalRead(k3));
}

void downnright()
{
  digitalWrite(k1, !digitalRead(k1));
  digitalWrite(k4, !digitalRead(k4));
}

void loop()
{

digitalWrite(k1, !digitalRead(k1));
delay(2000);
digitalWrite(k1, HIGH);
}
