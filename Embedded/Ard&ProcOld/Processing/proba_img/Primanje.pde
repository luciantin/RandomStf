void Primanje()
{
  in_serial_String=null;
  boolean primljeno=false;
 
  while(primljeno==false)
 {
   
   while(Port_1.available()>0) 
   {
     in_serial_String = Port_1.readStringUntil('\n');
   
     if(in_serial_String!=null) 
      {    
       in_serial_String=trim(in_serial_String);
       in_serial_Broj = Integer.parseInt(in_serial_String);
       vrijeme=millis();
       primljeno=true;
       }
    } 
  
  if(millis()-vrijeme>1500) 
    {
      in_serial_String="0";
      vrijeme=millis();
      primljeno=true;
    }
 
  }
  
}
