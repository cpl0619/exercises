/*int mydelay = 30;
int myspeed = analogRead(10);
void mstop()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  analogWrite(4, 0);
}
void counterclockwise()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  analogWrite(4, myspeed);
}
void clockwise()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  analogWrite(4, myspeed);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(6) == HIGH)
  {
    if (digitalRead(9) == HIGH)
    {
      clockwise();
    }
    if (digitalRead(9) == LOW)
    {
      counterclockwise();
    }
  }
  else
  {
    mstop();
  }
}*/
