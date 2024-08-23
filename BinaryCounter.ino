String find_binary(int num,int squares[])
{
  int j,l;
  String bin_str = "";
  String tempbin;
  for(j=0;j<4;j++)
  {
    if(num-squares[j] >= 0)
    {
      bin_str += "1";
      num -= squares[j];
    }
    else
    {
      bin_str += "0";
    }
  }
  if(bin_str.length() < 4)
  {
    tempbin = bin_str;
    bin_str = "";
    l = 4 - tempbin.length();
    for(j=1;j<=l;j++)
    {
      bin_str += "0";
    }
    bin_str += tempbin;
  }
  return bin_str;
}
void setup()
{
  Serial.begin(9600);
  int pins[] = {10,11,12,13};
  int i,j;
  int squares[] = {8,4,2,1};
  String bin[16];
  String tempbin;
  Serial.print("4 BIT BINARY COUNTER");
  Serial.print("\n");
  for(i=0;i<4;i++)
  {
    pinMode(pins[i], OUTPUT);
  }

  for(i=0;i<16;i++)
  {
    if(i!=0)
    {
      tempbin = find_binary(i,squares);
    }
    else
    {
      tempbin="0000";
    }
    bin[i] = tempbin;
  }

  for(i=0;i<16;i++)
  {
    tempbin = bin[i];
    for(j=0;j<4;j++)
    {
      if(tempbin[j] == '1')
      {
        digitalWrite(pins[j], HIGH);
      }
      else
      {
        digitalWrite(pins[j], LOW);
      }
    }
    Serial.print(String(i)+" --> "+bin[i]);
    Serial.print("\n");
    delay(3000);
  }
  for(j=0;j<4;j++)
  {
    {
      digitalWrite(pins[j], LOW);
    }
  }
  Serial.print("All LED's turned off.");
  Serial.print("\n");
}
void loop()
{
  // // No code ;)
}