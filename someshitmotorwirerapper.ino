int ena = 9;  //enable motor a
int enb = 10;  //enable motor b
int aup = 8;  // first motor counterclockwise
int adown = 11;  // first motor clockwise
int bup = 12; //second motor clockwise
int bdown = 13; // second motor counterclockwise

//int button = 3;

int topspead = 255;  // motor topspeed
int lowspeed = 80;  // motor low speed
int mediacore = 150;  // middle speed
int alto = 0;


void setup()
{
  //pinMode(3, INPUT);
  pinMode(9, OUTPUT);   //ena
  pinMode(10, OUTPUT);  //enb
  pinMode(8, OUTPUT);  // cc
  pinMode(11, OUTPUT);  //c
  pinMode(12, OUTPUT);  //cc
  pinMode(13, OUTPUT);   //c
  Serial.begin(9600);
  Serial.println("Welcome to CABLE REWINDER");
  delay(5000);
  Serial.println("Created by: ");
  Serial.println("Aaron , and Brandon ");
  delay(7000);
  analogWrite(ena, alto);
  analogWrite(enb, alto);
  Serial.println("Loading Program...... ");
  delay(4000);
  Serial.println("Please standby clear for testing and calibration");
  analogWrite(enb, lowspeed);
  analogWrite(ena, lowspeed);
  digitalWrite(aup, HIGH);
  digitalWrite(adown, LOW);
  digitalWrite(bup, LOW);
  digitalWrite(bdown, HIGH);
  delay(2000);
  analogWrite(enb, alto);
  analogWrite(ena, alto);
  digitalWrite(aup, HIGH);
  digitalWrite(adown, LOW);
  digitalWrite(bup, LOW);
  digitalWrite(bdown, HIGH);
  Serial.println("options : ");
    Serial.println(" h = hookup - starts initial wire feed phase");
    Serial.println(" p = prewind - secures wire for rewind phase");
    Serial.println(" x = halt - stops all current actions and motors");
    Serial.println(" w = rewind - starts cable rewidn phase");
  Serial.println("select your option now please");
}

void loop()
{
  if (Serial.available()) {
    int beginwinding = Serial.read();
    switch (beginwinding) {
      case 'h':
        hookup(200);
        Serial.println("plz feed cable into hole");
        delay(5000);// do something
        break;
      case 'p':
        prewind(200);
        Serial.println("cable should do a short burst of wind");
        delay(500);
        halt();
        delay(1000);
        prewind(200);
        delay(500);// do something
        break;
      case 'x':
        halt(200);
        Serial.println("has stoped return to prewind");
        break;
      case 'w':
        wind(200);
        Serial.println("cable should be winding up");
        break;
    }
  }
}


void hookup()
{
  analogWrite(enb, lowspeed);
  analogWrite(ena, lowspeed);
  digitalWrite(aup, HIGH);
  digitalWrite(adown, LOW);
  digitalWrite(bup, LOW);
  digitalWrite(bdown, HIGH);
}

void halt()
{
  analogWrite(enb, alto);
  analogWrite(ena, alto);
  digitalWrite(aup, LOW);
  digitalWrite(adown, LOW);
  digitalWrite(bup, LOW);
  digitalWrite(bdown, LOW);
}

void prewind()
{
  analogWrite(enb, topspead);
  analogWrite(ena, topspead);
  digitalWrite(aup, HIGH);
  digitalWrite(adown, LOW);
  digitalWrite(bup, LOW);
  digitalWrite(bdown, HIGH);
}

void wind()
{
  analogWrite(enb, mediacore);
  analogWrite(ena, mediacore);
  digitalWrite(aup, HIGH);
  digitalWrite(adown, LOW);
  digitalWrite(bup, LOW);
  digitalWrite(bdown, HIGH);
}

