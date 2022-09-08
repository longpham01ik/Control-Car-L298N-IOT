#include <SoftwareSerial.h>

#define ena 3   
#define in1 4
#define in2 5
#define in3 6
#define in4 7
#define enb 11
//Bluetooth value
int btValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);
}
void loop() {

    carControl();
}
void carControl()
{
  if (Serial.available() > 0)
  {
    btValue = Serial.read() - '0';
    Serial.println(btValue);
    if (btValue == 1)
    {
      moveForward();
    }
    else if (btValue == 2)
    {
      moveBackward();
    }
    else if (btValue == 3)
    {
      turnLeft();
    }
    else if (btValue == 4)
    {
      turnRight();
    }
    else if (btValue == 7)
    {
      roLeft();
    }
    else if (btValue == 8)
    {
      roRight();
    }
    else if (btValue == 5)
    {
      stopMove();
    }
  }
}
void getErrorCode()
{
}
//Hàm tiến
void moveForward()
{
  analogWrite(ena, 200);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enb, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
//Hàm lùi
void moveBackward()
{
  analogWrite(ena, 200);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enb, 200);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void turnLeft()
{
  analogWrite(ena, 140);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enb, 140);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void roLeft()
{
  analogWrite(ena, 60);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enb, 120);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void turnRight()
{
  analogWrite(ena, 140);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enb, 140);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void roRight()
{
  analogWrite(ena, 120);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enb, 60);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void stopMove()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}
