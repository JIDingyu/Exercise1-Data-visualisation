#include <LedControl.h>
int DIN = 10;
int CS =  8;
int CLK = 9;
const int analogPin=A0; 
const int digitalPin=7;             
int val = 0;
int aState = 0;
bool dState=0;

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup() 
{
  lc.shutdown(0,false);       
 lc.setIntensity(0,15);     
 lc.clearDisplay(0);        

 pinMode(DIN, OUTPUT);
 pinMode(CS, OUTPUT);
 pinMode(CLK,OUTPUT);
 pinMode(digitalPin,INPUT);
 Serial.begin(9600);
}



void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

void led()
{
  aState=analogRead(analogPin); 
  // Serial.print("A0: ");
  // Serial.println(aState); 
  dState=digitalRead(digitalPin); 
  // Serial.print("D0: ");
  // Serial.println(dState);
  if(dState==0) 
  {
   digitalWrite(DIN,HIGH);
   digitalWrite(CS, HIGH);
   digitalWrite(CLK, HIGH); 
   

   
   byte a[8]= {0x24,0x3d,0x7f,0xdb,0xfe,0xa4,0x24,0x24};
    byte b[8]= {0x24,0xbc,0xfe,0xdb,0x7f,0x25,0x64,0x04};
    byte c[8]= {0x24,0x3d,0x7f,0xdb,0xfe,0xa4,0x26,0x00};

  
    byte d[8]= {0x12,0x5e,0x7f,0x6d,0x3f,0x12,0x32,0x02};
    byte e[8]= {0x09,0x0f,0x1f,0x36,0x3f,0x29,0x09,0x08};
    byte f[8]= {0x04,0x17,0x1f,0x1b,0x0f,0x04,0x0c,0x00};
    byte g[8]= {0x02,0x03,0x07,0x0d,0x0f,0x0a,0x02,0x02};
    byte h[8]= {0x01,0x05,0x07,0x06,0x03,0x01,0x03,0x00};
    byte i[8]= {0x00,0x00,0x01,0x03,0x03,0x02,0x00,0x00};
    byte k[8]= {0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00};

    byte m[8]= {0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x00};
    byte n[8]= {0x00,0x00,0x40,0xc0,0xc0,0x80,0x00,0x00};
    byte o[8]= {0x20,0xa0,0xe0,0xc0,0x60,0x20,0x60,0x00};
    byte p[8]= {0x20,0x30,0x70,0xd0,0xf0,0xa0,0x20,0x20};
    byte q[8]= {0x20,0xb8,0xf8,0xd8,0x78,0x20,0x60,0x00};
    byte r[8]= {0x24,0x3c,0x7c,0xd8,0xfc,0xa4,0x24,0x20};
    byte s[8]= {0x24,0xbc,0xfe,0xda,0x7e,0x24,0x64,0x04};

    printByte(a); 
    delay(500);

    printByte(b);
    delay(500);

    printByte(c); 
    delay(500);
    
    printByte(d);
    delay(500);
    
    printByte(e);
    delay(500);
    
    printByte(f); 
    delay(500);
    
    printByte(g); 
    delay(500);
    
    printByte(h); 
    delay(500);
    
    printByte(i); 
    delay(500);
    
    printByte(k); 
    delay(500);

     printByte(m); 
    delay(500);

    printByte(n); 
    delay(500);
    
    printByte(o); 
    delay(500);
    
    printByte(p); 
    delay(500);

    printByte(q); 
    delay(500);
    
    printByte(r); 
    delay(500);
    
    printByte(s); 
    delay(500);
    
  
    lc.clearDisplay(0);
    
    delay(500);
  }


  else{
    digitalWrite(DIN,LOW);
    digitalWrite(CS, LOW); 
    digitalWrite(CLK, LOW); 
    
  }
}
void loop() 
{
  if (Serial.available()){
    String data= Serial.readString();
    //Serial.println(data);
    if (data=="1")
      {analogRead(analogPin); 
      aState=analogRead(analogPin);
      Serial.print(aState);
      }
    
  }
  led();
  
}
