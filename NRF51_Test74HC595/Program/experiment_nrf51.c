/*====================================================================================================*/
/*====================================================================================================*/
#include "nrf51_system.h"
#include "experiment_nrf51.h"
#include "module_sf595.h"
/*====================================================================================================*/
/*====================================================================================================*/
int main( void )
{
  uint8_t Count = 0;
  uint8_t State = 0;

  GPIO_Config();
  SF595_Config();
  SF595_Init();

  while(1) {
    nrf_gpio_pin_toggle(LED_1);
    nrf_gpio_pin_toggle(LED_2);
    Delay_10ms(10);

    Count++;

    switch(State) {

        case 0:
          if (Count == 8) {
            SF595_Shift(0);
            State = 1;
          }
          else {
            SF595_Shift(0);
          }
          break;

        case 1:
          if (Count == 16) {
            SF595_Shift(1);
            State = 2;
          }
          else {
            SF595_Shift(1);
          }
          break;

        case 2:
          for(; State>0; State--) {
            SF595_SendByte(0x00);
            Delay_100ms(2);
            SF595_SendByte(0xFF);
            Delay_100ms(2);
          }
          Count = 0;
          break;
    }
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void GPIO_Config( void )
{
  nrf_gpio_range_cfg_output(LED_1, LED_4);
}
/*====================================================================================================*/
/*====================================================================================================*/
