//Define Clock source
#define MCU_CLOCK_SOURCE      
#define MCU_CLOCK_SOURCE_HXT // HXT, LXT, HIRC, LIRC
#define MCU_CLOCK_FREQUENCY   50000000  //Hz

//Define MCU Interfaces
#define MCU_INTERFACE_SPI1
#define SPI1_CLOCK_SOURCE_PLL // HCLK, PLL
#define PIN_SPI1_SS0_PC8
#define PIN_SPI1_SCLK_PC9
#define PIN_SPI1_MISO0_PC10
#define PIN_SPI1_MOSI0_PC11

#define MCU_INTERFACE_SPI3     // LCD
#define SPI3_CLOCK_SOURCE_HCLK // HCLK, PLL
#define PIN_SPI3_SS0_PD8
#define PIN_SPI3_SCLK_PD9
#define PIN_SPI3_MISO0_PD10
#define PIN_SPI3_MOSI0_PD11

