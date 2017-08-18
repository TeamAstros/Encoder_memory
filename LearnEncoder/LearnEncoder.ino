#define akn 30

int e1,e2,ee1=0;
String E1,E2,YAW;
const int push = 22;
int encoderVal[5];
int haha;
int itr=0,caseFlag=1,sflag=0; 
int yaw;

void setup() 
{
  Serial.begin(9600);
  Serial1.begin(9600);  //sabertooth
  Serial2.begin(9600);  //encoder
  Serial3.begin(9600);  //imu

  pinMode(push,INPUT_PULLUP);
  pinMode(akn,INPUT_PULLUP);
  pinMode(50,OUTPUT);
  digitalWrite(50,HIGH);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() 
{
   
 /* readEncoders();
  if(!digitalRead(push))
  { 
    Serial.println("gaya re");
    while(!digitalRead(push));
    digitalWrite(50,LOW);
   delay(1000);
   digitalWrite(50,HIGH);
  }
  */
  if(caseFlag<=3)
   digitalWrite(13,LOW);
   
   readEncoders();
  if(!digitalRead(push) &&  itr<3) //Button Pressed
  {
    Serial.print("itr="+String(itr)+"_____");
    digitalWrite(13,HIGH);
    while(!digitalRead(push));
  /*  encoderVal[itr] = e1-ee1; //Current - Previous
    haha=e1;
    ee1=e1;*/
    encoderVal[itr]=e1;
    caseFlag++;
    itr++;
    Serial.println(e1);
  }
    
 else if(caseFlag>3 && sflag==0)
  {
    digitalWrite(13,HIGH);
    digitalWrite(50,LOW);
    delay(1);
    digitalWrite(50,HIGH);
   // Serial.println("YOO");
   // Serial.print(e1);
   // Serial.print(" ");
   // Serial.println(String(encoderVal[0])+"__"+String(encoderVal[1])+"__"+String(encoderVal[2]));
   // Serial.println();
   Serial.println("move");
    delay(3000);
    recall(); 
    sflag=1;
  }
  else if(sflag==1)
  {
   digitalWrite(13,LOW);
   delay(500);
   digitalWrite(13,HIGH); 
   Serial1.write(0);
  }
}
