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

int main(void)
{
    //	initializing
    SYS_Init(); 
    //	for LEDs
    GPIO_SetMode(PC, BIT12, GPIO_MODE_OUTPUT);
    GPIO_SetMode(PC, BIT13, GPIO_MODE_OUTPUT);
    GPIO_SetMode(PC, BIT14, GPIO_MODE_OUTPUT);
    GPIO_SetMode(PC, BIT15, GPIO_MODE_OUTPUT);
    // for buzzer
    GPIO_SetMode(PB, BIT11, GPIO_MODE_OUTPUT);


    while(1) {
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
