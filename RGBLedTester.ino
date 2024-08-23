const int red = 9;
const int green = 10;
const int blue = 11;
void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  digitalWrite(red, HIGH);
  delay(2000);
  digitalWrite(red, LOW);

  digitalWrite(green, HIGH);
  delay(2000);
  digitalWrite(green, LOW);

  digitalWrite(blue, HIGH);
  delay(2000);
  digitalWrite(blue, LOW);
}
void loop()
{
  // No code ;)
}