#include <Servo.h>

const int echo[] = { 49, 47,53};
const int trig[] = { 48, 46,52};

const int servo = 9;

Servo myservo;

const int buffer = 3;
char data_send[5*buffer];
char data_received[100];

int incoming_byte;
char incoming_text[100];
//deklarasi variabel
long duration;
int distance;

void setup()
{
  for (int i=0; i<buffer; i++){
    pinMode(trig[i], OUTPUT);
    pinMode(echo[i], INPUT);
  }
  pinMode(red, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(green, OUTPUT);
  myservo.attach(servo);

  //serial komunikasi
  Serial.begin(9600);
  Serial1.begin(4800);

}

void loop()
{
  //setup sensor
  int index = 0;
  for(int i=0; i<buffer; i++){
    digitalWrite(trig[i], LOW);
    delayMicroseconds(4);
    digitalWrite(trig[i], HIGH);
    delayMicroseconds(15);
    digitalWrite(trig[i], LOW);
  
  //perhitungan waktu dan jarak
    duration = pulseIn(echo[i],HIGH);
    distance = duration*(0.034/2);
    Serial.print(distance);
    Serial.print(" ");
  }

  digitalWrite(red, HIGH);
  digitalWrite(white, HIGH);
  digitalWrite(green, HIGH);

  myservo.write(27);

  Serial.println();

  int available_bytes = Serial1.available();
  for(int i = 0; i< available_bytes; i++){
    incoming_text[i] = Serial1.read();
    incoming_text[i] = '\0';
  }

  delay(1500);
}
