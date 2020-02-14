# SETUP #

Setup je uvijek isti, koji god mode se koristi

## PRIVATE VAR ##

UART_HandleTypeDef <var_name>

UART handle Structure

~~~~
  UART_HandleTypeDef huart4;
~~~~


## Initilisation ## 


### .Instance ###

Sets register address, which Peripheral to use

Peripheral list in stm32f407xx.h line 1071

### .Init ###

- Baudrate
- WordLength - size of packet without controll bits
- StopBits - 1 or 2 stop bits
- Parity 
- Mode
- HwFlowCtl
- OverSampling

~~~~
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 115200;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  
  .
  .
  .
  
  void Error_Handler(void){//Handle}
~~~~