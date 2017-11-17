int pin = 3; //interrupt pin, 3 is int.1
//volatile int state = HIGH; //pin 13 led react with interrupt
volatile int incount1  = 0; //value for number of interrpts in given time frame

void setup() {

  Serial.begin(9600); //start serial com
  
  pinMode(pin,INPUT);
  pinMode(13,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pin),triggerISR,HIGH); //attach interrupt

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
  }

void triggerISR(){
//  state = !state;     //pin 13 led react with interrupt
  incount1++;         //count digital signal state changes
//  Serial.print("*");
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt
  Serial.println(incount1);
  incount1=0;
}


