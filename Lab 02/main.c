//
// GPIO_7seg_keypad : 3x3 keypad inpt and display on 7-segment LEDs
//
#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "Seven_Segment.h"
#include "Scankey.h"

// display an integer on four 7-segment LEDs
void Display_7seg(uint16_t value)
{
  uint8_t digit;
digit = value / 1000;
CloseSevenSegment();
ShowSevenSegment(3,digit);
CLK_SysTickDelay(5000);

value = value - digit * 1000;
digit = value / 100;
CloseSevenSegment();
ShowSevenSegment(2,digit);
CLK_SysTickDelay(5000);

value = value - digit * 100;
digit = value / 10;
CloseSevenSegment();
ShowSevenSegment(1,digit);
CLK_SysTickDelay(5000);

value = value - digit * 10;
digit = value;
CloseSevenSegment();
ShowSevenSegment(0,digit);
CLK_SysTickDelay(5000);
}


void Buzz(int number)
{
int i;
for (i=0; i<number; i++) {
      PB11=0; // PB11 = 0 to turn on Buzzer
 CLK_SysTickDelay(100000); // Delay
 PB11=1; // PB11 = 1 to turn off Buzzer
 CLK_SysTickDelay(100000); // Delay
}
}


int main(void)
{
//uint16_t i;
int passcode = 1111; // our answer.
int i = 3;
int j = 0;
int k = 0;
int s = 0;
int code; // user enter code.

    SYS_Init();
GPIO_SetMode(PB, BIT11, GPIO_MODE_OUTPUT);

    OpenSevenSegment();
 OpenKeyPad();


   while(1) {

k = ScanKey();
if ( k != 0){
s = s*10 + k;
i--;
if (i < 0){
//for (j = 0; j < 50; j++) Display_7seg(s);
i = 3;
code = s;
s = 0;
if(code == passcode) Buzz(5);
else Buzz(2);

for (j = 0; j < 50; j++) Display_7seg(code/1000); Buzz(1);
for (j = 0; j < 50; j++) Display_7seg(code/100); Buzz(1);
for (j = 0; j < 50; j++) Display_7seg(code/10); Buzz(1);
for (j = 0; j < 50; j++) Display_7seg(code/1); Buzz(1);
/*
for (j = 0; j < 50; j++) Display_7seg((code%10)*10); Buzz(1);
for (j = 0; j < 50; j++) Display_7seg((code%10)*100); Buzz(1);
for (j = 0; j < 50; j++) Display_7seg((code%10)*1000); Buzz(1);
*/
}
}

for (j = 0; j < 10; j++) Display_7seg(s);
 }
}