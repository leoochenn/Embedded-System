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
int code=0;
int i=1;
int j=0;
int k=0;
int s=0;
volatile uint8_t ledState =0;


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


void TMR1_IRQHandler(void)
{	
	if(code > 0){
	int j=0;
	ledState = ~ ledState;  // changing ON/OFF state
	Buzz(1);
	code--;
	
	for (j=0; j<20; j++) Display_7seg(code);
  if(ledState) PC12=0;
  else         PC12=1;
	for (j=0; j<20; j++) Display_7seg(code);
  TIMER_ClearIntFlag(TIMER1); // Clear Timer1 time-out interrupt flag
	
	if(code==0)
	{
		Buzz(5);
	}
		}
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
	start:
	i=1;
	j=0;
	k=0;
	s=0;
	code=0;
    SYS_Init();
		GPIO_SetMode(PC, BIT12, GPIO_MODE_OUTPUT); // set LED GPIO pin
		

    OpenSevenSegment(); // for 7-segment
	  OpenKeyPad();       // for keypad
    GPIO_SetMode(PB, BIT11, GPIO_MODE_OUTPUT); // for Buzzer
		
	// INITIALIZE TIMER TO FIX CODE
			

		
	//	Display_7seg(code); // display code (50 times for vision)
 	  while(1) {
		  k=ScanKey();
			if (k!=0) {
				s = s*10 + k;			
	      printf("key=%d i=%d s=%d\n", k, i, s); // add retarget.c to library & set DEBUG_ENABLE_SEMIHOST in config.
				i--;
				if (i<0) {
					i=1;
					code=s+1;
					s=0;			
			    //Display_7seg(code); // display code (50 times for vision)
				}
			}
			for (j=0; j<10; j++) Display_7seg(s); // display s (10 times for keypad debounce)
			if (code>9)break;
	  }
	
		Init_Timer1();
	
	
	//ends with buzz
	Buzz(5);
	
	if(code==0)
	{
		goto start;
	}
	
}