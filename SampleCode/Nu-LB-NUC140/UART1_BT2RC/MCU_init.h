//Define Clock source
#define MCU_CLOCK_SOURCE      
#define MCU_CLOCK_SOURCE_HXT  // HXT, LXT, HIRC, LIRC
#define MCU_CLOCK_FREQUENCY   50000000  //Hz

//Define MCU Interfaces
// LCD using SPI3
#define MCU_INTERFACE_SPI3
#define SPI3_CLOCK_SOURCE_HCLK // HCLK, PLL
#define PIN_SPI3_SS0_PD8
#define PIN_SPI3_SCLK_PD9
#define PIN_SPI3_MISO0_PD10
#define PIN_SPI3_MOSI0_PD11

// Bluetooth (HC05) using UART1
#define MCU_INTERFACE_UART1
#define UART_CLOCK_SOURCE_HXT // HXT, LXT, PLL, HIRC
#define UART_CLOCK_DIVIDER     3
#define PIN_UART1_RX_PB4
#define PIN_UART1_TX_PB5
