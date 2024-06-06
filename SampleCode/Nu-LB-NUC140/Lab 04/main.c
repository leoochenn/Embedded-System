//
// GPIO_7seg_keypad4_buzz : 
//     keypad input 4 digits and display on 7-segment LEDs
//     compare 4 digits to a passcode 
//     if input is equal to then passcode, then buzz twice
//
#include <stdio.h>
#include <math.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "Seven_Segment.h"
#include "Scankey.h"
 
 	uint32_t cumdown;
 
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
	  CLK_SysTickDelay(100000);	 // Delay 
	  PB11=1; // PB11 = 1 to turn off Buzzer	
	  CLK_SysTickDelay(100000);	 // Delay 
	}
}
 
volatile uint8_t ledState[4] ={0,0,0,0};
 
void TMR1_IRQHandler(void)
{
  ledState[1] = ~ ledState[1];  // changing ON/OFF state
	cumdown--;
	Display_7seg(cumdown);
	if(cumdown == 0){
		
	}
  if(ledState[1]) PC13=0;
  else            PC13=1;
  TIMER_ClearIntFlag(TIMER1); // Clear Timer1 time-out interrupt flag
}
 
void Init_Timer1(void)
{
  TIMER_Open(TIMER1, TMR1_OPERATING_MODE, TMR1_OPERATING_FREQ);
  TIMER_EnableInt(TIMER1);
  NVIC_EnableIRQ(TMR1_IRQn);
  TIMER_Start(TIMER1);	
}
 
int main(void)
{

	int i=3;
	int j=0;
	int k=0;
	int s=0;
	int code;	
 
    SYS_Init();
 
    OpenSevenSegment(); // for 7-segment
	  OpenKeyPad();       // for keypad
    GPIO_SetMode(PB, BIT11, GPIO_MODE_OUTPUT); // for Buzzer
		GPIO_SetMode(PC, (BIT12 | BIT13 | BIT14 | BIT15), GPIO_MODE_OUTPUT); // set LED GPIO pin
 
		Init_Timer1();
 
 	  while(1) {
		  k=ScanKey();
			if (k!=0) {
				s = s*10 + k;			
	      printf("key=%d i=%d s=%d\n", k, i, s); // add retarget.c to library & set DEBUG_ENABLE_SEMIHOST in config.
				i--;
				if (i<0) {
					i=1;
					cumdown=s;
					s=0;
					
					Init_Timer1();

          
				}
			}
		}
}