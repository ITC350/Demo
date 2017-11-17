const int servo=3;
const int dc_has=10;
const int dc_ret1=11;
const int dc_ret2=12;

unsigned long tid;

void setup() 
{ 
  pinMode(servo, OUTPUT);   // sets the pin as output
  pinMode(dc_has, OUTPUT);   // sets the pin as output
  pinMode(dc_ret1, OUTPUT);   // sets the pin as output
  pinMode(dc_ret2, OUTPUT);   // sets the pin as output
} 

void loop() 
{ 
  //frem
  analogWrite(servo, 50);
  analogWrite(dc_has, 35);
  digitalWrite(dc_ret1,HIGH);
  digitalWrite(dc_ret2,LOW);
  delay(1000);
  //tilbage
  analogWrite(servo, 180);
  analogWrite(dc_has, 35);
  digitalWrite(dc_ret1,LOW);
  digitalWrite(dc_ret2,HIGH);
  delay(1000);
} 
