#define akn 4

int cnt=0;

void setup() 
{
pinMode(2,INPUT_PULLUP);
pinMode(akn,OUTPUT);
Serial.begin(9600);
}

byte val=9999;

void loop() 
{
  attachInterrupt(digitalPinToInterrupt(2),count,RISING);
  detachInterrupt(digitalPinToInterrupt(2));
  //if(Serial.available())
    val=Serial.read();
  if(cnt>=val)
  {
   // Serial.println("LOWWWW");//always remove this ,juts for checking purpose
     digitalWrite(akn,LOW);
     delay(5000 );
  }
  else
    digitalWrite(akn,HIGH);   
}

void count()
{
  cnt++;
  Serial.print((int)cnt);
  Serial.println("/");
  Serial.flush();
 }


