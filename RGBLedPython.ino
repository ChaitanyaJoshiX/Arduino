const int red_pin = 9;
const int green_pin = 10;
const int blue_pin = 11;
int red_input, green_input, blue_input;

void LightLED(int red_input, int green_input, int blue_input)
{
  analogWrite(red_pin, red_input);
  analogWrite(green_pin, green_input);
  analogWrite(blue_pin, blue_input);
}

void setup()
{
  Serial.begin(115200); 
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
}

void loop()
{
  if(Serial.available() >= 3)
  {
    red_input = Serial.read();
    green_input = Serial.read();
    blue_input = Serial.read();   
    LightLED(red_input, green_input, blue_input);
  }
}