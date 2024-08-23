const int buzzer_pin = 8;
const int button_pin = 7; 
const int red_pin = 12;
const int blue_pin = 13;
int base_flag = 0, past_state=0, current_state, press_count = 1;

void Light()
{
  if(base_flag == 0)
  {
    digitalWrite(blue_pin, LOW);
    digitalWrite(red_pin, HIGH);
    base_flag = 1;
  }
  else
  {
    digitalWrite(red_pin, LOW);
    digitalWrite(blue_pin, HIGH);
    base_flag = 0;
  }
  delay(250);
}

void Buzzer()
{
  if(base_flag == 0)
  {
    digitalWrite(buzzer_pin, HIGH);
  }
  else
  {
    digitalWrite(buzzer_pin, LOW);
  }
}

void BeginEvent()
{
  Light();
  Buzzer();
}

void EndEvent()
{
  digitalWrite(blue_pin, LOW);
  digitalWrite(red_pin, LOW);
  digitalWrite(buzzer_pin, LOW);
}

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  pinMode(button_pin, INPUT);
}
void loop()
{
  current_state = digitalRead(button_pin);
  if(current_state == HIGH && past_state == LOW)
  {
    press_count++;
    Serial.println(press_count);
  }
  if(press_count%2 == 0)
  {
    BeginEvent();
  }
  else
  {
    EndEvent();
  }
  past_state = current_state;
}
