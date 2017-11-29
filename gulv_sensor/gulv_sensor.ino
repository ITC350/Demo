int analogPin = A3;     // potentiometer wiper (middle terminal) connected to analog pin 3
// outside leads to ground and +5V
int val = 0;           // variable to store the value read
//int hvid = 150;
//int sort = 850;
//int gulv = 450;

void setup()
{
  Serial.begin(9600);              //  setup serial
  pinMode(analogPin, INPUT);
}

void loop()
{
  detect(850,150);
  delay(100);
}

void detect(int sort, int hvid) {
  int border = ((sort - hvid)/2)+hvid;
  //Serial.println(border);             // debug value check
  val = analogRead(analogPin);     // read the input pin
  //  Serial.println(val);             // debug value
  if (val > border){
    Serial.println("ABS");             // debug status
  }
}

