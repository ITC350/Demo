//sensor
int inpin1 = 18; //interrupt pin, 18 is int.5
int inpin2 = 19; //interrupt pin, 19 is int.4
int inpin3 = 2; //interrupt pin, 20 is int.3
int inpin4 = 3; //interrupt pin, 21 is int.2

volatile unsigned int in1_time = 0; 
volatile unsigned int in2_time = 0;
volatile unsigned int in3_time = 0;
volatile unsigned int in4_time = 0;

void setup()
{
  Serial.begin(9600);
  //sensor
  pinMode(inpin1, INPUT);
  pinMode(inpin2, INPUT);
  pinMode(inpin3, INPUT);
  pinMode(inpin4, INPUT);
  attachInterrupt(digitalPinToInterrupt(inpin1), triggerISR1, HIGH); //attach interrupt
  attachInterrupt(digitalPinToInterrupt(inpin2), triggerISR2, HIGH); //attach interrupt
  attachInterrupt(digitalPinToInterrupt(inpin3), triggerISR3, HIGH); //attach interrupt
  attachInterrupt(digitalPinToInterrupt(inpin4), triggerISR4, HIGH); //attach interrupt

  noInterrupts();//stop interrupts

  //Timer5 16 bit
  //  #######################################################
  TCCR5A = 0;               //set entire TCCR1A register to 0
  TCCR5B = 0;               //set entire TCCR1B register to 0
  TCNT5 = 0;                //Register for timer value

  TCCR5B |= (1 << CS52) | (1 << CS50);    // prescaler
  TCCR1B |= (0 << WGM52);   //Normal mode

  interrupts();//allow interrupts

}

void loop()
{ 

}

void triggerISR1() {
//  Serial.println(TCNT5);
  Serial.println(TCNT5 - in1_time);
  in1_time = TCNT5;
}

void triggerISR2() {
  Serial.println(TCNT5 - in2_time);
  in2_time = TCNT5;
}

void triggerISR3() {
  Serial.println(TCNT5 - in3_time);
  in3_time = TCNT5;
}

void triggerISR4() {
  Serial.println(TCNT5 - in4_time);
  in4_time = TCNT5;
}



