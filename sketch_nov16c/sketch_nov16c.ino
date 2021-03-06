int inpin1 = 18; //interrupt pin, 3 is int.5
int inpin2 = 19; //interrupt pin, 3 is int.4
int inpin3 = 20; //interrupt pin, 3 is int.3
int inpin4 = 21; //interrupt pin, 3 is int.2
//volatile int state = HIGH; //pin 13 led react with interrupt
volatile int incount1  = 0; //value for number of interrpts in given time frame
volatile int incount2  = 0; //value for number of interrpts in given time frame
volatile int incount3  = 0; //value for number of interrpts in given time frame
volatile int incount4  = 0; //value for number of interrpts in given time frame

void setup() {

  Serial.begin(9600); //start serial com

  pinMode(inpin1, INPUT);
  pinMode(inpin2, INPUT);
  pinMode(inpin3, INPUT);
  pinMode(inpin4, INPUT);
  pinMode(51, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(inpin1), triggerISR1, HIGH); //attach interrupt
  attachInterrupt(digitalPinToInterrupt(inpin2), triggerISR2, HIGH); //attach interrupt
  attachInterrupt(digitalPinToInterrupt(inpin3), triggerISR3, HIGH); //attach interrupt
  attachInterrupt(digitalPinToInterrupt(inpin4), triggerISR4, HIGH); //attach interrupt

  noInterrupts();//stop interrupts
  //Timer1 16 bit
  TCCR1A = 0;               //set entire TCCR1A register to 0
  TCCR1B = 0;               //set entire TCCR1B register to 0
  TCNT1 = 0;                //Register for timer value

  OCR1A = 62500;            //compare match register 16MHz/256/1Hz  1 hz timer
  TCCR1B |= (1 << WGM12);   //CTC mode
  TCCR1B |= (1 << CS12);    //256 prescaler
  TIMSK1 |= (1 << OCIE1A);  //enable timer compare interrupt

  interrupts();//allow interrupts
}

void loop() {
  //digitalWrite(13, state);    //pin 13 led react with interrupt
  digitalWrite(51, 1);
  delay(100);
  digitalWrite(51, 0);
  delay(100);
}

void triggerISR1() {
  //  state = !state;     //pin 13 led react with interrupt
  incount1++;         //count digital signal state changes
  //  Serial.print("*");
}

void triggerISR2() {
  //  state = !state;     //pin 13 led react with interrupt
  incount2++;         //count digital signal state changes
  //  Serial.print("*");
}

void triggerISR3() {
  //  state = !state;     //pin 13 led react with interrupt
  incount3++;         //count digital signal state changes
  //  Serial.print("*");
}

void triggerISR4() {
  //  state = !state;     //pin 13 led react with interrupt
  incount4++;         //count digital signal state changes
  //  Serial.print("*");
}

ISR(TIMER1_COMPA_vect) { //timer1 interrupt
  Serial.print(incount1);
  Serial.print(":");
  Serial.println(incount2);
  Serial.print(incount3);
  Serial.print(":");
  Serial.println(incount4);
  Serial.println("###########");
  incount1 = 0;
  incount2 = 0;
  incount3 = 0;
  incount4 = 0;
}


