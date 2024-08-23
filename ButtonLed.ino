const int button = 8;
const int led = 7;
int state = 0;
void setup()
{
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}
void loop()
{
  state = digitalRead(button);
  if(state == HIGH)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}