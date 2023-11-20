#include <Servo.h>
#include <math.h>

int ldr = A0;
int ldr2 = A1;
int ldr3 = A2;
Servo motor;

void setup()
{
  pinMode(ldr, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  motor.attach(3);
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(ldr);
  int reading2 = analogRead(ldr2);
  int reading3 = analogRead(ldr3);

  //servo motor turn angle
  moveMotor(reading, reading2, reading3);
}

void  moveMotor(int reading1, int reading2, int reading3)
{
  int result;
  int diffA = reading1 - reading2;
  int diffB = reading3 - reading2;

  if (abs(diffA) > abs(diffB))
  {
    result = map(diffA, -900, 900, 90, 0);
  }
  else
  {
    result = map(diffB, -900, 900, 90, 180);
  }
  motor.write(result);
}
