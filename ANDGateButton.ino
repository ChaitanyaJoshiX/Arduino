int inp1_pin = 12, inp2_pin= 13, button_pin = 8, current_state = 0, past_state = 0, print_flag = 0,  i = 1;
String inp_arr[] = {"00", "01", "10", "11"};
int inp1, inp2;
void runcycle(int i)
{
  inp1 = (inp_arr[i][0]) - '0';
  inp2 = (inp_arr[i][1]) - '0';
  digitalWrite(inp1_pin, inp1);
  digitalWrite(inp2_pin, inp2);
}
void setup()
{
  Serial.begin(9600);
  pinMode(inp1_pin, OUTPUT);
  pinMode(inp2_pin, OUTPUT);
  pinMode(button_pin, INPUT);
}
void loop()
{
  current_state = digitalRead(button_pin);
  if(current_state == HIGH)
  {
    if(i==4)
    {
      i=0;
    }
    else
    {
      if(print_flag == 1)
      {
        Serial.println("Mode "+ String((i+1)));
        print_flag = 0;
      }
      runcycle(i);
    }
  }
  else if(current_state == 0 && past_state == 1)
  {
    digitalWrite(inp1_pin, LOW);
    digitalWrite(inp2_pin, LOW);
    print_flag = 1;
    i++;
  }
  else
  {
    // Empty
  }
  past_state = current_state;
}
