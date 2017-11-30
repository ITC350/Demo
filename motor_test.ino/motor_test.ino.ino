const int servo=5;
const int dc_has=10;
const int dc_ret1=11;
const int dc_ret2=12;

unsigned long tid;

void setup()
{
    TCCR3B = TCCR3B & 0b11111000 | 0x04;
  pinMode(servo, OUTPUT);   // sets the pin as output
  pinMode(dc_has, OUTPUT);   // sets the pin as output
  pinMode(dc_ret1, OUTPUT);   // sets the pin as output
  pinMode(dc_ret2, OUTPUT);   // sets the pin as output
}

void loop()
{
  //frem
  analogWrite(servo, 31);
  analogWrite(dc_has, 35);
  digitalWrite(dc_ret1,HIGH);
  digitalWrite(dc_ret2,LOW);
  delay(1000);
//  //tilbage
//  analogWrite(servo, 64);
//  analogWrite(dc_has, 35);
//  digitalWrite(dc_ret1,LOW);
//  digitalWrite(dc_ret2,HIGH);
//  delay(1000);
}
