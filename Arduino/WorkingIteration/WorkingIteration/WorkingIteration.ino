const int buttonPin = 0;
int buttonState = 0;
int Row1 = 1;
int Row2 = 2;
int Row3 = 3;
int Row4 = 4;
int Row5 = 5;
int Row6 = 6;
int Row7 = 7;
int Row8 = 8;
int RSerial = 9;
int BSerial = 10;
int GSerial = 11;
int RCLK = 12;
int SCLK = 13;
int forLoop = 0;

byte green[8];
byte red[8];
byte blue[8];

int startAnim = 0; 
int counting = 0;
bool _isCounting = false;
// Set up arrays, select one of these three things to display
#include <elapsedMillis.h>
//DEFAULT
byte Bbitmap [8]={0,0,0,0,0,0,0,0};
byte Gbitmap [8]={0,0,0,0,0,0,0,0};
byte Rbitmap [8]={0,0,0,0,0,0,0,0};
// RGB Flag
//byte Bbitmap [8]={240, 240, 240, 240, 0, 0, 0, 0};
//byte Gbitmap [8]={15, 0, 15, 0, 255, 0, 255, 0};
//byte Rbitmap [8]={0, 15, 0, 15, 0, 255, 0, 255};
// Blue Face
//byte Bbitmap [8]={60, 126, 255, 219, 255, 219, 102, 60};
//byte Gbitmap [8]={60, 126, 129, 165, 129, 129,   0,  0};
//byte Rbitmap [8]={60, 126,   0,  36,   0,  36,  24,  0};
// Red Car
//byte Gbitmap [8]={8, 0, 0, 0, 0, 0, 255, 255};
//byte Bbitmap [8]={255, 255, 255, 131, 0, 0, 0, 0};
//byte Rbitmap [8]={8, 0, 0, 124, 255, 189, 0, 0};
#include <elapsedMillis.h>  
unsigned int interval = 100;
// Set the pins to output to the array
void setup() {
  _isCounting = false;
  counting = 1;
  startAnim = 0;
  pinMode(buttonPin, INPUT);
  pinMode(Row1, OUTPUT);
  pinMode(Row2, OUTPUT);
  pinMode(Row3, OUTPUT);
  pinMode(Row4, OUTPUT);
  pinMode(Row5, OUTPUT);
  pinMode(Row6, OUTPUT);
  pinMode(Row7, OUTPUT);
  pinMode(Row8, OUTPUT);
  pinMode(BSerial, OUTPUT);
  pinMode(GSerial, OUTPUT);
  pinMode(RSerial, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SCLK, OUTPUT);
  buttonState == LOW;
}
elapsedMillis elapsedTime;
void loop() {
  byte Gbitmap [8]={green[0], green[1], green[2], green[3], green[4], green[5], green[6], green[7]};
  byte Bbitmap [8]={blue[0],  blue[1],  blue[2],  blue[3],  blue[4],  blue[5],  blue[6],  blue[7]};
  byte Rbitmap [8]={red[0],   red[1],   red[2],   red[3],   red[4],   red[5],   red[6],   red[7]};
  for (int row = 0; row <8; row++){
    //turn everything off
    digitalWrite (Row1, LOW);
    digitalWrite (Row2, LOW);
    digitalWrite (Row3, LOW);
    digitalWrite (Row4, LOW);
    digitalWrite (Row5, LOW);
    digitalWrite (Row6, LOW);
    digitalWrite (Row7, LOW);
    digitalWrite (Row8, LOW);
    // set up the data in the shift registers
    for (int shiftbit = 0; shiftbit <8; shiftbit++){
      digitalWrite(BSerial, HIGH);
      digitalWrite(GSerial, HIGH);
      digitalWrite(RSerial, HIGH);
      if bitRead(Bbitmap[row],shiftbit) digitalWrite(BSerial, LOW);
      if bitRead(Gbitmap[row],shiftbit) digitalWrite(GSerial, LOW);
      if bitRead(Rbitmap[row],shiftbit) digitalWrite(RSerial, LOW);
      digitalWrite(SCLK, LOW);
      digitalWrite(SCLK, HIGH);
      }
    //latch the data
    digitalWrite(RCLK, HIGH);
    digitalWrite(RCLK, LOW); 
    // turn on the associated row
    if (row == 0) digitalWrite (Row1, HIGH);
    if (row == 1) digitalWrite (Row2, HIGH); 
    if (row == 2) digitalWrite (Row3, HIGH); 
    if (row == 3) digitalWrite (Row4, HIGH); 
    if (row == 4) digitalWrite (Row5, HIGH); 
    if (row == 5) digitalWrite (Row6, HIGH); 
    if (row == 6) digitalWrite (Row7, HIGH); 
    if (row == 7) digitalWrite (Row8, HIGH);
    delay(2);  
  }  
        buttonState = digitalRead(buttonPin);
         if (buttonState == LOW) {
          startAnim = true;
          _isCounting = true;
         }
       if (startAnim == true && _isCounting == true)
        {
          if (counting == 1)
           {
            blue[0] = 0;
            blue[1] = 0;
            blue[2] = 0;
            blue[3] = 0;
            blue[4] = 0;
            blue[5] = 0;
            blue[6] = 0;
            blue[7] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 2)
           { 
            blue[7] = 158;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];            
           }
          if (counting == 3)
           { 
            blue[6] = 158;
            blue[7] = 146;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 4)
           { 
            blue[5] = 158;
            blue[6] = 146;
            blue[7] = 146;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 5)
           { 
            blue[4] = 158;
            blue[5] = 146;
            blue[6] = 146;
            blue[7] = 242;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 6)
           { 
            blue[3] = 158;
            blue[4] = 146;
            blue[5] = 146;
            blue[6] = 242;
            blue[7] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 7)
           { 
            blue[2] = 158;
            blue[3] = 146;
            blue[4] = 146;
            blue[5] = 242;
            blue[6] = 0;
            blue[7] = 254;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 8)
           { 
            blue[1] = 158;
            blue[2] = 146;
            blue[3] = 146;
            blue[4] = 242;
            blue[5] = 0;
            blue[6] = 254;
            blue[7] = 16;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 9)
           { 
            blue[0] = 158;
            blue[1] = 146;
            blue[2] = 146;
            blue[3] = 242;
            blue[4] = 0;
            blue[5] = 254;
            blue[6] = 16;
            blue[7] = 16;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 10)
           { 
            blue[0] = 146;
            blue[1] = 146;
            blue[2] = 242;
            blue[3] = 0;
            blue[4] = 254;
            blue[5] = 16;
            blue[6] = 16;
            blue[7] = 254;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 11)
           { 
            blue[0] = 146;
            blue[1] = 242;
            blue[2] = 0;
            blue[3] = 254;
            blue[4] = 16;
            blue[5] = 16;
            blue[6] = 254;
            blue[7] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 12)
           { 
            blue[0] = 242;
            blue[1] = 0;
            blue[2] = 254;
            blue[3] = 16;
            blue[4] = 16;
            blue[5] = 254;
            blue[6] = 0;
            blue[7] = 254;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 13)
           { 
            blue[0] = 0;
            blue[1] = 254;
            blue[2] = 16;
            blue[3] = 16;
            blue[4] = 254;
            blue[5] = 0;
            blue[6] = 254;
            blue[7] = 146;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 14)
           { 
            blue[0] = 254;
            blue[1] = 16;
            blue[2] = 16;
            blue[3] = 254;
            blue[4] = 0;
            blue[5] = 254;
            blue[6] = 146;
            blue[7] = 146;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 15)
           { 
            blue[0] = 16;
            blue[1] = 16;
            blue[2] = 254;
            blue[3] = 0;
            blue[4] = 254;
            blue[5] = 146;
            blue[6] = 146;
            blue[7] = 146;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 16)
           { 
            blue[0] = 16;
            blue[1] = 254;
            blue[2] = 0;
            blue[3] = 254;
            blue[4] = 146;
            blue[5] = 146;
            blue[6] = 146;
            blue[7] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 17)
           { 
            blue[0] = 254;
            blue[1] = 0;
            blue[2] = 254;
            blue[3] = 146;
            blue[4] = 146;
            blue[5] = 146;
            blue[6] = 0;
            blue[7] = 254;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 18)
           { 
            blue[0] = 0;
            blue[1] = 254;
            blue[2] = 146;
            blue[3] = 146;
            blue[4] = 146;
            blue[5] = 0;
            blue[6] = 254;
            blue[7] = 146;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 19)
           { 
            blue[0] = 254;
            blue[1] = 146;
            blue[2] = 146;
            blue[3] = 146;
            blue[4] = 0;
            blue[5] = 254;
            blue[6] = 146;
            blue[7] = 146;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 20)
           { 
            blue[0] = 146;
            blue[1] = 146;
            blue[2] = 146;
            blue[3] = 0;
            blue[4] = 254;
            blue[5] = 146;
            blue[6] = 146;
            blue[7] = 146;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 21)
           { 
            blue[0] = 146;
            blue[1] = 146;
            blue[2] = 0;
            blue[3] = 254;
            blue[4] = 146;
            blue[5] = 146;
            blue[6] = 146;
            blue[7] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 22)
           { 
            blue[0] = 146;
            blue[1] = 0;
            blue[2] = 254;
            blue[3] = 146;
            blue[4] = 146;
            blue[5] = 146;
            blue[6] = 0;
            blue[7] = 254;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 23)
           { 
            blue[0] = 0;
            blue[1] = 254;
            blue[2] = 146;
            blue[3] = 146;
            blue[4] = 146;
            blue[5] = 0;
            blue[6] = 254;
            blue[7] = 18;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 24)
           { 
            blue[0] = 254;
            blue[1] = 146;
            blue[2] = 146;
            blue[3] = 146;
            blue[4] = 0;
            blue[5] = 254;
            blue[6] = 18;
            blue[7] = 18;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 25)
           { 
            blue[0] = 146;
            blue[1] = 146;
            blue[2] = 146;
            blue[3] = 0;
            blue[4] = 254;
            blue[5] = 18;
            blue[6] = 18;
            blue[7] = 12;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 26)
           { 
            blue[0] = 146;
            blue[1] = 146;
            blue[2] = 0;
            blue[3] = 254;
            blue[4] = 18;
            blue[5] = 18;
            blue[6] = 12;
            blue[7] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 27)
           { 
            blue[0] = 146;
            blue[1] = 0;
            blue[2] = 254;
            blue[3] = 18;
            blue[4] = 18;
            blue[5] = 12;
            blue[6] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 28)
           { 
            blue[0] = 0;
            blue[1] = 254;
            blue[2] = 18;
            blue[3] = 18;
            blue[4] = 12;
            blue[5] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 29)
           { 
            blue[0] = 254;
            blue[1] = 18;
            blue[2] = 18;
            blue[3] = 12;
            blue[4] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 30)
           { 
            blue[0] = 18;
            blue[1] = 18;
            blue[2] = 12;
            blue[3] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 31)
           { 
            blue[0] = 18;
            blue[1] = 12;
            blue[2] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 32)
           { 
            blue[0] = 12;
            blue[1] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 33)
           { 
            blue[0] = 0;
            red[0] = 255-blue[0];
            red[1] = 255-blue[1];
            red[2] = 255-blue[2];
            red[3] = 255-blue[3];
            red[4] = 255-blue[4];
            red[5] = 255-blue[5];
            red[6] = 255-blue[6];
            red[7] = 255-blue[7];
            green[0] = 255-blue[0];
            green[1] = 255-blue[1];
            green[2] = 255-blue[2];
            green[3] = 255-blue[3];
            green[4] = 255-blue[4];
            green[5] = 255-blue[5];
            green[6] = 255-blue[6];
            green[7] = 255-blue[7];
           }
          if (counting == 34)
           {
            red[0] = 0;
            red[1] = 0;
            red[2] = 0;
            red[3] = 0;
            red[4] = 0;
            red[5] = 0;
            red[6] = 0;
            red[7] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 35)
           { 
            red[7] = 158;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 36)
           { 
            red[6] = 158;
            red[7] = 146;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 37)
           { 
            red[5] = 158;
            red[6] = 146;
            red[7] = 146;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 38)
           { 
            red[4] = 158;
            red[5] = 146;
            red[6] = 146;
            red[7] = 242;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 39)
           { 
            red[3] = 158;
            red[4] = 146;
            red[5] = 146;
            red[6] = 242;
            red[7] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 40)
           { 
            red[2] = 158;
            red[3] = 146;
            red[4] = 146;
            red[5] = 242;
            red[6] = 0;
            red[7] = 254;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 41)
           { 
            red[1] = 158;
            red[2] = 146;
            red[3] = 146;
            red[4] = 242;
            red[5] = 0;
            red[6] = 254;
            red[7] = 16;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 42)
           { 
            red[0] = 158;
            red[1] = 146;
            red[2] = 146;
            red[3] = 242;
            red[4] = 0;
            red[5] = 254;
            red[6] = 16;
            red[7] = 16;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 43)
           { 
            red[0] = 146;
            red[1] = 146;
            red[2] = 242;
            red[3] = 0;
            red[4] = 254;
            red[5] = 16;
            red[6] = 16;
            red[7] = 254;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 44)
           { 
            red[0] = 146;
            red[1] = 242;
            red[2] = 0;
            red[3] = 254;
            red[4] = 16;
            red[5] = 16;
            red[6] = 254;
            red[7] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 45)
           { 
            red[0] = 242;
            red[1] = 0;
            red[2] = 254;
            red[3] = 16;
            red[4] = 16;
            red[5] = 254;
            red[6] = 0;
            red[7] = 254;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 46)
           { 
            red[0] = 0;
            red[1] = 254;
            red[2] = 16;
            red[3] = 16;
            red[4] = 254;
            red[5] = 0;
            red[6] = 254;
            red[7] = 146;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 47)
           { 
            red[0] = 254;
            red[1] = 16;
            red[2] = 16;
            red[3] = 254;
            red[4] = 0;
            red[5] = 254;
            red[6] = 146;
            red[7] = 146;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 48)
           { 
            red[0] = 16;
            red[1] = 16;
            red[2] = 254;
            red[3] = 0;
            red[4] = 254;
            red[5] = 146;
            red[6] = 146;
            red[7] = 146;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 49)
           { 
            red[0] = 16;
            red[1] = 254;
            red[2] = 0;
            red[3] = 254;
            red[4] = 146;
            red[5] = 146;
            red[6] = 146;
            red[7] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 50)
           { 
            red[0] = 254;
            red[1] = 0;
            red[2] = 254;
            red[3] = 146;
            red[4] = 146;
            red[5] = 146;
            red[6] = 0;
            red[7] = 254;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 51)
           { 
            red[0] = 0;
            red[1] = 254;
            red[2] = 146;
            red[3] = 146;
            red[4] = 146;
            red[5] = 0;
            red[6] = 254;
            red[7] = 146;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 52)
           { 
            red[0] = 254;
            red[1] = 146;
            red[2] = 146;
            red[3] = 146;
            red[4] = 0;
            red[5] = 254;
            red[6] = 146;
            red[7] = 146;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 53)
           { 
            red[0] = 146;
            red[1] = 146;
            red[2] = 146;
            red[3] = 0;
            red[4] = 254;
            red[5] = 146;
            red[6] = 146;
            red[7] = 146;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 54)
           { 
            red[0] = 146;
            red[1] = 146;
            red[2] = 0;
            red[3] = 254;
            red[4] = 146;
            red[5] = 146;
            red[6] = 146;
            red[7] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 55)
           { 
            red[0] = 146;
            red[1] = 0;
            red[2] = 254;
            red[3] = 146;
            red[4] = 146;
            red[5] = 146;
            red[6] = 0;
            red[7] = 254;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 56)
           { 
            red[0] = 0;
            red[1] = 254;
            red[2] = 146;
            red[3] = 146;
            red[4] = 146;
            red[5] = 0;
            red[6] = 254;
            red[7] = 18;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 57)
           { 
            red[0] = 254;
            red[1] = 146;
            red[2] = 146;
            red[3] = 146;
            red[4] = 0;
            red[5] = 254;
            red[6] = 18;
            red[7] = 18;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 58)
           { 
            red[0] = 146;
            red[1] = 146;
            red[2] = 146;
            red[3] = 0;
            red[4] = 254;
            red[5] = 18;
            red[6] = 18;
            red[7] = 12;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 59)
           { 
            red[0] = 146;
            red[1] = 146;
            red[2] = 0;
            red[3] = 254;
            red[4] = 18;
            red[5] = 18;
            red[6] = 12;
            red[7] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 60)
           { 
            red[0] = 146;
            red[1] = 0;
            red[2] = 254;
            red[3] = 18;
            red[4] = 18;
            red[5] = 12;
            red[6] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 61)
           { 
            red[0] = 0;
            red[1] = 254;
            red[2] = 18;
            red[3] = 18;
            red[4] = 12;
            red[5] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 62)
           { 
            red[0] = 254;
            red[1] = 18;
            red[2] = 18;
            red[3] = 12;
            red[4] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 63)
           { 
            red[0] = 18;
            red[1] = 18;
            red[2] = 12;
            red[3] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 64)
           { 
            red[0] = 18;
            red[1] = 12;
            red[2] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 65)
           { 
            red[0] = 12;
            red[1] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 66)
           { 
            red[0] = 0;
            green[0] = 255-red[0];
            green[1] = 255-red[1];
            green[2] = 255-red[2];
            green[3] = 255-red[3];
            green[4] = 255-red[4];
            green[5] = 255-red[5];
            green[6] = 255-red[6];
            green[7] = 255-red[7];
           }
          if (counting == 67)
           {
            green[0] = 0;
            green[1] = 0;
            green[2] = 0;
            green[3] = 0;
            green[4] = 0;
            green[5] = 0;
            green[6] = 0;
            green[7] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 68)
           { 
            green[7] = 158;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 69)
           { 
            green[6] = 158;
            green[7] = 146;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 70)
           { 
            green[5] = 158;
            green[6] = 146;
            green[7] = 146;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 71)
           { 
            green[4] = 158;
            green[5] = 146;
            green[6] = 146;
            green[7] = 242;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 72)
           { 
            green[3] = 158;
            green[4] = 146;
            green[5] = 146;
            green[6] = 242;
            green[7] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 73)
           { 
            green[2] = 158;
            green[3] = 146;
            green[4] = 146;
            green[5] = 242;
            green[6] = 0;
            green[7] = 254;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 74)
           { 
            green[1] = 158;
            green[2] = 146;
            green[3] = 146;
            green[4] = 242;
            green[5] = 0;
            green[6] = 254;
            green[7] = 16;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 75)
           { 
            green[0] = 158;
            green[1] = 146;
            green[2] = 146;
            green[3] = 242;
            green[4] = 0;
            green[5] = 254;
            green[6] = 16;
            green[7] = 16;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 76)
           { 
            green[0] = 146;
            green[1] = 146;
            green[2] = 242;
            green[3] = 0;
            green[4] = 254;
            green[5] = 16;
            green[6] = 16;
            green[7] = 254;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 77)
           { 
            green[0] = 146;
            green[1] = 242;
            green[2] = 0;
            green[3] = 254;
            green[4] = 16;
            green[5] = 16;
            green[6] = 254;
            green[7] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 78)
           { 
            green[0] = 242;
            green[1] = 0;
            green[2] = 254;
            green[3] = 16;
            green[4] = 16;
            green[5] = 254;
            green[6] = 0;
            green[7] = 254;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 79)
           { 
            green[0] = 0;
            green[1] = 254;
            green[2] = 16;
            green[3] = 16;
            green[4] = 254;
            green[5] = 0;
            green[6] = 254;
            green[7] = 146;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 80)
           { 
            green[0] = 254;
            green[1] = 16;
            green[2] = 16;
            green[3] = 254;
            green[4] = 0;
            green[5] = 254;
            green[6] = 146;
            green[7] = 146;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 81)
           { 
            green[0] = 16;
            green[1] = 16;
            green[2] = 254;
            green[3] = 0;
            green[4] = 254;
            green[5] = 146;
            green[6] = 146;
            green[7] = 146;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 82)
           { 
            green[0] = 16;
            green[1] = 254;
            green[2] = 0;
            green[3] = 254;
            green[4] = 146;
            green[5] = 146;
            green[6] = 146;
            green[7] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 83)
           { 
            green[0] = 254;
            green[1] = 0;
            green[2] = 254;
            green[3] = 146;
            green[4] = 146;
            green[5] = 146;
            green[6] = 0;
            green[7] = 254;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 84)
           { 
            green[0] = 0;
            green[1] = 254;
            green[2] = 146;
            green[3] = 146;
            green[4] = 146;
            green[5] = 0;
            green[6] = 254;
            green[7] = 146;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 85)
           { 
            green[0] = 254;
            green[1] = 146;
            green[2] = 146;
            green[3] = 146;
            green[4] = 0;
            green[5] = 254;
            green[6] = 146;
            green[7] = 146;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 86)
           { 
            green[0] = 146;
            green[1] = 146;
            green[2] = 146;
            green[3] = 0;
            green[4] = 254;
            green[5] = 146;
            green[6] = 146;
            green[7] = 146;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 87)
           { 
            green[0] = 146;
            green[1] = 146;
            green[2] = 0;
            green[3] = 254;
            green[4] = 146;
            green[5] = 146;
            green[6] = 146;
            green[7] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 88)
           { 
            green[0] = 146;
            green[1] = 0;
            green[2] = 254;
            green[3] = 146;
            green[4] = 146;
            green[5] = 146;
            green[6] = 0;
            green[7] = 254;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 89)
           { 
            green[0] = 0;
            green[1] = 254;
            green[2] = 146;
            green[3] = 146;
            green[4] = 146;
            green[5] = 0;
            green[6] = 254;
            green[7] = 18;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 90)
           { 
            green[0] = 254;
            green[1] = 146;
            green[2] = 146;
            green[3] = 146;
            green[4] = 0;
            green[5] = 254;
            green[6] = 18;
            green[7] = 18;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 91)
           { 
            green[0] = 146;
            green[1] = 146;
            green[2] = 146;
            green[3] = 0;
            green[4] = 254;
            green[5] = 18;
            green[6] = 18;
            green[7] = 12;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 92)
           { 
            green[0] = 146;
            green[1] = 146;
            green[2] = 0;
            green[3] = 254;
            green[4] = 18;
            green[5] = 18;
            green[6] = 12;
            green[7] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 93)
           { 
            green[0] = 146;
            green[1] = 0;
            green[2] = 254;
            green[3] = 18;
            green[4] = 18;
            green[5] = 12;
            green[6] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 94)
           { 
            green[0] = 0;
            green[1] = 254;
            green[2] = 18;
            green[3] = 18;
            green[4] = 12;
            green[5] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 95)
           { 
            green[0] = 254;
            green[1] = 18;
            green[2] = 18;
            green[3] = 12;
            green[4] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 96)
           { 
            green[0] = 18;
            green[1] = 18;
            green[2] = 12;
            green[3] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 97)
           { 
            green[0] = 18;
            green[1] = 12;
            green[2] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 98)
           { 
            green[0] = 12;
            green[1] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
           }
          if (counting == 99)
           { 
            green[0] = 0;
            blue[0] = 255-green[0];
            blue[1] = 255-green[1];
            blue[2] = 255-green[2];
            blue[3] = 255-green[3];
            blue[4] = 255-green[4];
            blue[5] = 255-green[5];
            blue[6] = 255-green[6];
            blue[7] = 255-green[7];
            counting = 0;
           }
         elapsedmillisloop();
  } 
}
    void elapsedmillisloop() {
      if (startAnim = true) 
      {
        if (elapsedTime > interval) 
        {
        counting++;
        elapsedTime = 0;
        }
      }
    }
