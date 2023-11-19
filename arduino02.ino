#include <Servo.h>

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
  int brightestSensor = brightest(reading, reading2, reading3);

  //sensor readings
  Serial.print("Reading 1: ");
  Serial.print(reading);
  Serial.println(" ");
  delay(500);
  Serial.print("Reading 2: ");
  Serial.print(reading2);
  Serial.println(" ");
  delay(500);
  Serial.print("Reading 3: ");
  Serial.print(reading3);
  Serial.println(" ");
  delay(500);

  //servo motor turn angle
  moveMotor(brightestSensor);
  // delay(5000);
}

int brightest(int reading1, int reading2, int reading3)
{
  if (reading1 > reading2 && reading1 > reading3)
    return (ldr);
  else if (reading2 > reading1 && reading2 > reading3)
    return (ldr2);
  else
    return (ldr3);
}

void  moveMotor(int brightestLdr)
{
  if (brightestLdr == ldr)
    motor.write(180);
  else if (brightestLdr == ldr2)
    motor.write(90);
  else
    motor.write(0);
}