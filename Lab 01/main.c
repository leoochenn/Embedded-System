//
// GPIO_LED : GPIO output to control an on-board red LED
// 
// EVB : Nu-LB-NUC140
// MCU : NUC140VE3CN

// low-active output control by GPC12

#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

//  copy the Buzz function from ~/Nu-LB-NUC140_BSP3.00.004_v1.4.5/SampleCode/Nu-LB-NUC140/GPIO_Buzzer
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

//  main function
int main(void)
{
    //	initializing
    SYS_Init(); 
    //	initial LEDs
    GPIO_SetMode(PC, BIT12, GPIO_MODE_OUTPUT);
    GPIO_SetMode(PC, BIT13, GPIO_MODE_OUTPUT);
    GPIO_SetMode(PC, BIT14, GPIO_MODE_OUTPUT);
    GPIO_SetMode(PC, BIT15, GPIO_MODE_OUTPUT);
    //  initial buzzer
    GPIO_SetMode(PB, BIT11, GPIO_MODE_OUTPUT);

    //  Leds bounce back and fourth, and buzzer buzz.
    while(1) 
        // first
        PC12 =0; // turn on LED
        CLK_SysTickDelay(100000);	 // Delay 
        PC12 =1; // turn off LED
        CLK_SysTickDelay(100000);	 // Delay
        Buzz(1);

        //	second
        PC13 =0; // turn on LED
        CLK_SysTickDelay(100000);	 // Delay 
        PC13 =1; // turn off LED
        CLK_SysTickDelay(100000);	 // Delay
        Buzz(1);

        //	third
        PC14 =0; // turn on LED
        CLK_SysTickDelay(100000);	 // Delay 
        PC14 =1; // turn off LED
        CLK_SysTickDelay(100000);	 // Delay
        Buzz(1);

        //	fourth
        PC15 =0; // turn on LED
        CLK_SysTickDelay(100000);	 // Delay 
        PC15 =1; // turn off LED
        CLK_SysTickDelay(100000);	 // Delay
        Buzz(1);

        //	third
        PC14 =0; // turn on LED
        CLK_SysTickDelay(100000);	 // Delay 
        PC14 =1; // turn off LED
        CLK_SysTickDelay(100000);	 // Delay
        Buzz(1);

        //	second
        PC13 =0; // turn on LED
        CLK_SysTickDelay(100000);	 // Delay 
        PC13 =1; // turn off LED
        CLK_SysTickDelay(100000);	 // Delay
        Buzz(1);
    }
}
