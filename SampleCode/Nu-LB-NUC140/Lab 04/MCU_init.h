//Define Clock source
#define MCU_CLOCK_SOURCE      
#define MCU_CLOCK_SOURCE_HXT  // HXT, LXT, HIRC, LIRC
#define MCU_CLOCK_FREQUENCY   50000000  //Hz

//Define MCU Interfaces
#define MCU_INTERFACE_TMR1
#define TMR1_CLOCK_SOURCE_HXT // HXT, LXT, HCLK, EXT, LIRC, HIRC
#define TMR1_CLOCK_DIVIDER    1
#define TMR1_OPERATING_MODE   TIMER_PERIODIC_MODE // ONESHOT, PERIODIC, TOGGLE, CONTINUOUS
#define TMR1_OPERATING_FREQ   1 //Hz