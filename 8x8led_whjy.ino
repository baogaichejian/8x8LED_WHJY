#include <LedControl.h>
#include <Wire.h>
const int DIN = 7;
const int CLK = 9;
const int CS = 8;
LedControl led = LedControl(DIN, CLK, CS , 4);

byte whjy[][1]=
  { 0x19F,0x65,0x2D,0x24,0x20,0xFF,0x20,0xA7,
    0x8A,0x52,0x20,0x52,0x8A,0x88,0x8A,0xFA,
    0xD,0xA,0xEA,0xAA,0xAA,0xEF,0x2,0x2,
    0xFA,0xAA,0xF8,0xAA,0xAA,0xF8,0x22,0x22,
    };
byte kong[][1]{0x00};
void showWordByPtr(LedControl led, byte (*word)[1]);
void showwhjy();
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; ++i)
  {
    led.shutdown(i, false);//关闭省电模式，这一步必须做，否则显示不出来(因为在构造函数中，默认开启了省电模式，所以，我们要关闭该模式)。
    led.clearDisplay(i);//清空数据
    led.setIntensity(i,2);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  showwhjy();
  delay(5000);
  for(int i=0;i<5;i++){
      //showWordByPtr(led,kong);
      for(int l=0;l<4;l++){
      led.clearDisplay(l);}
      delay(100);
      showwhjy();
      delay(100);
  }

}

void showWordByPtr(LedControl led, byte (*word)[1])
{ int temp1=0;
  for (int i = 0; i < 4; ++i)
  {
    
    for (int j = 0; j < 8; ++j)
      {
        led.setRow(i, j, *(*(word + j)+temp1));
      }
      temp1 +=8;
  }
  
}

void showwhjy(){
      showWordByPtr(led, whjy);
}
