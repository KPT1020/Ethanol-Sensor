#include <Arduino.h>
//TXD from sensor to RX of Arduino
byte inByte;
int index = 0;
int array[10];
int a,b,c,d,e,f,g,h,i,j;
int x;
int check;
float data;
float multi;
void setup(){
  Serial.begin(9600);
}

void loop(){
while (Serial.available() )
 { 
   inByte = Serial.read(); // Read a Byte
  // Serial.print(index);
   array[index]=inByte;
   index++;
 
   if(index==10){
    a=array[0];b=array[1];c=array[2];d=array[3];e=array[4];f=array[5];g=array[6];h=array[7];i=array[8];j=array[9];
     check=c+d+e+f+g+h+i;
   // Serial.print("check=");Serial.println(check);
     // Serial.print("j=");Serial.println(j);
    x=check;
    if(check>255){
     x=check%256;
    //Serial.print("x= "); Serial.println(x);
    }

 if(x==j){
      if(a!=0xff){
        Serial.println("Data is abnormal, location unmatch,please pres restart on board");
       Serial.print("a=");Serial.print(a); Serial.print(" ");  Serial.print("b="); Serial.print(b);  Serial.print(" "); Serial.print("c="); Serial.print(c);Serial.print(" ");   Serial.print("d="); Serial.print(d); Serial.print(" "); Serial.print("e=");  Serial.print(e); Serial.print(" "); 
    Serial.print("f=");Serial.print(f);Serial.print(" ");   Serial.print("g="); Serial.print(g); Serial.print(" ");  Serial.print("h="); Serial.print(h);Serial.print(" ");  Serial.print("i=");  Serial.print(i);Serial.print(" ");Serial.print("j=");  Serial.print(j);Serial.print(" ");

      }
     if(d=0x00){
      multi=1;}
      if(d=0x01){
      multi=0.1;}
       if(d=0x02){
      multi=0.01;}
        if(d=0x03){
      multi=0.001;}
      
      unsigned int resultVal = (uint16_t)e << 8 | f;
   // Serial.print(") The arduino received: ");Serial.print(array[0]);Serial.print(" ");Serial.print(array[1]);Serial.print(" ");Serial.print(array[2]);Serial.print(" ");Serial.println(array[3]);
    /*Serial.print(") The arduino received: "); Serial.print("a=");Serial.print(a); Serial.print(" ");  Serial.print("b="); Serial.print(b);  Serial.print(" "); Serial.print("c="); Serial.print(c);Serial.print(" ");   Serial.print("d="); Serial.print(d); Serial.print(" "); Serial.print("e=");  Serial.print(e); Serial.print(" "); 
    Serial.print("f=");Serial.print(f);Serial.print(" ");   Serial.print("g="); Serial.print(g); Serial.print(" ");  Serial.print("h="); Serial.print(h);Serial.print(" ");  Serial.print("i=");  Serial.print(i);Serial.print(" ");Serial.print("j=");  Serial.print(j);Serial.print(" ");
 */
    data=float(resultVal)*multi;
   Serial.print("The ethanol conc. is :"); Serial.print(data);Serial.println("ppm");
    index=0;
   // }
 }
    else {
      Serial.println("Data is abnormal, checking unmatch");
  // Serial.print(array[0]);Serial.print(" ");Serial.print(array[1]);Serial.print(" ");Serial.print(array[2]);Serial.print(" ");Serial.println(array[3]);
   Serial.print(") The arduino received: ");Serial.print("a=");Serial.print(a); Serial.print(" ");  Serial.print("b="); Serial.print(b);  Serial.print(" "); Serial.print("c="); Serial.print(c);Serial.print(" ");   Serial.print("d="); Serial.print(d); Serial.print(" "); Serial.print("e=");  Serial.print(e); Serial.print(" "); 
    Serial.print("f=");Serial.print(f);Serial.print(" ");   Serial.print("g="); Serial.print(g); Serial.print(" ");  Serial.print("h="); Serial.print(h);Serial.print(" ");  Serial.print("i=");  Serial.print(i);Serial.print(" ");Serial.print("j=");  Serial.print(j);Serial.print(" ");
 index=0;

    }
   }
}
}


     

   /*Serial.print("a=");Serial.print(a); Serial.print(" ");  Serial.print("b="); Serial.print(b);  Serial.print(" "); Serial.print("c="); Serial.print(c);Serial.print(" ");   Serial.print("d="); Serial.print(d); Serial.print(" "); Serial.print("e=");  Serial.print(e); Serial.print(" "); 
    Serial.print("f=");Serial.print(f);Serial.print(" ");   Serial.print("g="); Serial.print(g); Serial.print(" ");  Serial.print("h="); Serial.print(h);Serial.print(" ");  Serial.print("i=");  Serial.print(i);Serial.print(" ");Serial.print("j=");  Serial.print(j);Serial.print(" ");
 */
  