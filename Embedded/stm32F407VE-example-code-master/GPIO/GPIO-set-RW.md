
## GPIO SET R/W ##


### SET ###
~~~~
/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE3 PE4 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}
~~~~




### READ ###

~~~~
GPIO_PinState var;
var = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3);
if(var == GPIO_PIN_SET) //1
else if(var == GPIO_PIN_RESET) //0
~~~~




### WRITE ###


~~~~
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);

HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
~~~~


## CONST ##


### PIN STATE ###

~~~~
GPIO_PIN_SET -> 1
GPIO_PIN_RESET -> 0
~~~~

### GPIO PIN STRUCT ###

~~~~
  uint32_t Pin;       Specifies the GPIO pins to be configured.This parameter can be any value of @ref GPIO_pins_define 

  uint32_t Mode;      Specifies the operating mode for the selected pins.This parameter can be a value of @ref GPIO_mode_define 

  uint32_t Pull;      Specifies the Pull-up or Pull-Down activation for the selected pins. This parameter can be a value of @ref GPIO_pull_define 

  uint32_t Speed;     Specifies the speed for the selected pins. This parameter can be a value of @ref GPIO_speed_define 

  uint32_t Alternate; Peripheral to be connected to the selected pins. This parameter can be a value of @ref GPIO_Alternate_function_selection 
~~~~


### MODE ###

~~~~
#define  GPIO_MODE_INPUT                        Input Floating Mode                   
#define  GPIO_MODE_OUTPUT_PP                    Output Push Pull Mode                 
#define  GPIO_MODE_OUTPUT_OD                    Output Open Drain Mode                
#define  GPIO_MODE_AF_PP                        Alternate Function Push Pull Mode     
#define  GPIO_MODE_AF_OD                        Alternate Function Open Drain Mode    

#define  GPIO_MODE_ANALOG                       Analog Mode  
    
#define  GPIO_MODE_IT_RISING                    External Interrupt Mode with Rising edge trigger detection          
#define  GPIO_MODE_IT_FALLING                   External Interrupt Mode with Falling edge trigger detection         
#define  GPIO_MODE_IT_RISING_FALLING            External Interrupt Mode with Rising/Falling edge trigger detection  
 
#define  GPIO_MODE_EVT_RISING                   External Event Mode with Rising edge trigger detection               
#define  GPIO_MODE_EVT_FALLING                  External Event Mode with Falling edge trigger detection              
#define  GPIO_MODE_EVT_RISING_FALLING           External Event Mode with Rising/Falling edge trigger detection       
~~~~

### SPEED ###

~~~~
#define  GPIO_SPEED_FREQ_LOW         IO works at 2 MHz, please refer to the product datasheet 
#define  GPIO_SPEED_FREQ_MEDIUM      range 12,5 MHz to 50 MHz, please refer to the product datasheet
#define  GPIO_SPEED_FREQ_HIGH        range 25 MHz to 100 MHz, please refer to the product datasheet  
#define  GPIO_SPEED_FREQ_VERY_HIGH   range 50 MHz to 200 MHz, please refer to the product datasheet  
~~~~


### PULL ###

~~~~
#define  GPIO_NOPULL        No Pull-up or Pull-down activation
#define  GPIO_PULLUP        Pull-up activation               
#define  GPIO_PULLDOWN      Pull-down activation            
~~~~











