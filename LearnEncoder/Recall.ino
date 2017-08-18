void recall()
{
  for(int i=0;i<3;i++)
  {
    Serial1.write(0);
    delay(1000);
    Serial.println("in for");
    while(true)
    {
      Serial2.write(encoderVal[i]);
      Serial.println("in while ------>"+String(digitalRead(akn)));
      Serial.println(digitalRead(akn));
      if(digitalRead(akn)==LOW)
      {
        Serial1.write(0);
        while(digitalRead(akn)==LOW);
       Serial.println("in if");
       Serial.println("....");
       break;
      }
      Serial1.write(54);
      Serial1.write(183s);
      /* if(e1>=encoderVal[i]) 
      {
      //  Serial1.write(0);
        Serial.println("in if");
      //  delay(2000);
        Serial.println("....");
        break;
      }*/
     }
   }
}

