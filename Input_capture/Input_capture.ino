//sensor
int ICP1 = 999;   //interrupt pin, timer 1, PD4 - OBS pin unmapped ¯\_(ツ)_/¯
int ICP3 = 999;   //interrupt pin, timer 3, PE7 - OBS pin unmapped  ¯\_(ツ)_/¯
int ICP4 = 49;  //interrupt pin, timer 4, PL1
int ICP5 = 48;  //interrupt pin, timer 5, PL0

unsigned int tim1_time = 0;
unsigned int tim3_time = 0;
unsigned int tim4_time = 0;
unsigned int tim5_time = 0;

void setup()
{
  Serial.begin(9600);
  //sensor
  pinMode(2, OUTPUT);    //pin for software test of ICPn
  pinMode(3, OUTPUT);    //pin for software test of ICPn
  pinMode(4, OUTPUT);    //pin for software test of ICPn
  pinMode(5, OUTPUT);    //pin for software test of ICPn
  pinMode(ICP1, INPUT);     //timer 1 pin PD4 ICP1
  pinMode(ICP3, INPUT);     //timer 3 pin PE7 ICP3
  pinMode(ICP4, INPUT);     //timer 4 pin PL1 ICP4
  pinMode(ICP5, INPUT);     //timer 5 pin PL0 ICP5


  noInterrupts();//stop interrupts

  //Timer1 16 bit
  //  #######################################################
  TCCR1A = 0;               //set entire TCCR1A register to 0
  TCCR1B = 0;               //set entire TCCR1B register to 0
  TCNT1 = 0;                //Register for timer value

  TCCR1B |= (1 << CS12);    // prescaler
  TCCR1B |= (1 << ICNC1);    //Noice canceler on
  TCCR1B |= (1 << ICES1);    //Interrupt on RISING
  TIMSK1 |= (1 << ICIE1);  //enable timer interrupt
  TIFR1 |= (1 << ICF1); // Clear ICF flag - just in case


  //Timer3 16 bit
  //  #######################################################
  TCCR3A = 0;               //set entire TCCR1A register to 0
  TCCR3B = 0;               //set entire TCCR1B register to 0
  TCNT3 = 0;                //Register for timer value

  TCCR3B |= (1 << CS32);    // prescaler
  TCCR3B |= (1 << ICNC3);    //Noice canceler on
  TCCR3B |= (1 << ICES3);    //Interrupt on RISING
  TIMSK3 |= (1 << ICIE3);  //enable timer interrupt
  TIFR3 |= (1 << ICF3); // Clear ICF flag - just in case


  //Timer4 16 bit
  //  #######################################################
  TCCR4A = 0;               //set entire TCCR1A register to 0
  TCCR4B = 0;               //set entire TCCR1B register to 0
  TCNT4 = 0;                //Register for timer value

  TCCR4B |= (1 << CS42);    // prescaler
  TCCR4B |= (1 << ICNC3);    //Noice canceler on
  TCCR4B |= (1 << ICES3);    //Interrupt on RISING
  TIMSK4 |= (1 << ICIE3);  //enable timer interrupt
  TIFR4 |= (1 << ICF3); // Clear ICF flag - just in case


  //Timer5 16 bit
  //  #######################################################
  TCCR5A = 0;               //set entire TCCR1A register to 0
  TCCR5B = 0;               //set entire TCCR1B register to 0
  TCNT5 = 0;                //Register for timer value

  TCCR5B |= (1 << CS52);    // prescaler
  TCCR5B |= (1 << ICNC5);    //Noice canceler on
  TCCR5B |= (1 << ICES5);    //Interrupt on RISING
  TIMSK5 |= (1 << ICIE5);  //enable timer interrupt
  TIFR5 |= (1 << ICF5); // Clear ICF flag - just in case

  interrupts();//allow interrupts

}

void loop()
{
  digitalWrite(2, 1);
//  digitalWrite(3, 1);
//  digitalWrite(4, 1);
//  digitalWrite(5, 1);
  delay(100);
  digitalWrite(2, 0);
//  digitalWrite(3, 0);
//  digitalWrite(4, 0);
//  digitalWrite(5, 0);
  delay(100);
}

//Timer 1 interrrput
ISR(TIMER1_CAPT_vect) {
  Serial.println("1");
  //Serial.println(ICR1);
//  Serial.println(ICR1 - tim1_time);
//  tim1_time = ICR1;
}

//Timer 3 interrrput
ISR(TIMER3_CAPT_vect) {
  Serial.println("3");
  //Serial.println(ICR3);
//  Serial.println(ICR3 - tim3_time);
//  tim3_time = ICR3;
}

//Timer 4 interrrput
ISR(TIMER4_CAPT_vect) {
  Serial.println("4");
  //Serial.println(ICR4);
//  Serial.println(ICR4 - tim4_time);
//  tim4_time = ICR4;
}

//Timer 5 interrrput
ISR(TIMER5_CAPT_vect) {
  Serial.println("5");
  //Serial.println(ICR5);
//  Serial.println(ICR5 - tim5_time);
//  tim5_time = ICR5;
}


