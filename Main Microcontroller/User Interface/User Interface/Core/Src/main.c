/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "sensorObjects.h"
#include "Letters.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LCD_8B2L 0x38 // ; Enable 8 bit data, 2 display lines
#define LCD_DCB 0x0F // ; Enable Display, Cursor, Blink
#define LCD_MCR 0x06 // ; Set Move Cursor Right
#define LCD_CLR 0x01 // ; Home and clear LCD
#define LCD_LN1 0x80 // ;Set DDRAM to start of line 1
#define LCD_LN2 0xC0 // ; Set DDRAM to start of line 2
#define LCD_CM_ENA 0x00210002 //
#define LCD_CM_DIS 0x00230000 //
#define LCD_DM_ENA 0x00200003 //
#define LCD_DM_DIS 0x00220001 //
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart3;

/* Definitions for XbeeTask */
osThreadId_t XbeeTaskHandle;
const osThreadAttr_t XbeeTask_attributes = {
  .name = "XbeeTask",
  .priority = (osPriority_t) osPriorityAboveNormal1,
  .stack_size = 128 * 4
};
/* Definitions for UserTask */
osThreadId_t UserTaskHandle;
const osThreadAttr_t UserTask_attributes = {
  .name = "UserTask",
  .priority = (osPriority_t) osPriorityAboveNormal2,
  .stack_size = 128 * 4
};
/* Definitions for SolenoidTask */
osThreadId_t SolenoidTaskHandle;
const osThreadAttr_t SolenoidTask_attributes = {
  .name = "SolenoidTask",
  .priority = (osPriority_t) osPriorityAboveNormal3,
  .stack_size = 128 * 4
};
/* Definitions for WeatherTask */
osThreadId_t WeatherTaskHandle;
const osThreadAttr_t WeatherTask_attributes = {
  .name = "WeatherTask",
  .priority = (osPriority_t) osPriorityAboveNormal4,
  .stack_size = 128 * 4
};
/* Definitions for FlowTask */
osThreadId_t FlowTaskHandle;
const osThreadAttr_t FlowTask_attributes = {
  .name = "FlowTask",
  .priority = (osPriority_t) osPriorityAboveNormal5,
  .stack_size = 128 * 4
};
/* Definitions for ProcessingTask */
osThreadId_t ProcessingTaskHandle;
const osThreadAttr_t ProcessingTask_attributes = {
  .name = "ProcessingTask",
  .priority = (osPriority_t) osPriorityAboveNormal6,
  .stack_size = 128 * 4
};
/* Definitions for FlowQueue */
osMessageQueueId_t FlowQueueHandle;
const osMessageQueueAttr_t FlowQueue_attributes = {
  .name = "FlowQueue"
};
/* Definitions for WeatherQueue */
osMessageQueueId_t WeatherQueueHandle;
const osMessageQueueAttr_t WeatherQueue_attributes = {
  .name = "WeatherQueue"
};
/* Definitions for XbeeQueue */
osMessageQueueId_t XbeeQueueHandle;
const osMessageQueueAttr_t XbeeQueue_attributes = {
  .name = "XbeeQueue"
};
/* Definitions for SolenoidQueue */
osMessageQueueId_t SolenoidQueueHandle;
const osMessageQueueAttr_t SolenoidQueue_attributes = {
  .name = "SolenoidQueue"
};
/* Definitions for UserQueue */
osMessageQueueId_t UserQueueHandle;
const osMessageQueueAttr_t UserQueue_attributes = {
  .name = "UserQueue"
};
/* USER CODE BEGIN PV */
int count=0;
int val[6];
int indc, time, onoff;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART3_UART_Init(void);
void StartXbeeTask(void *argument);
void StartUserTask(void *argument);
void StartSolenoidTask(void *argument);
void StartWeatherTask(void *argument);
void StartFlowTask(void *argument);
void StartProcessingTask(void *argument);

/* USER CODE BEGIN PFP */
void commandToLCD(void);
void printPassword(void);
void printCol(void);
void line1(void);
void line2(void);
void clear(void);
void correct(void);
void getVal(int);
void wrongPass(void);
void green(void);
void timer(void);
void quit(void);
void onOffTime(void);
void onOff(void);
void flow (void);
void setSolenoids(int, int);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of FlowQueue */
  FlowQueueHandle = osMessageQueueNew (16, sizeof(uint16_t), &FlowQueue_attributes);

  /* creation of WeatherQueue */
  WeatherQueueHandle = osMessageQueueNew (16, sizeof(uint16_t), &WeatherQueue_attributes);

  /* creation of XbeeQueue */
  XbeeQueueHandle = osMessageQueueNew (16, sizeof(uint16_t), &XbeeQueue_attributes);

  /* creation of SolenoidQueue */
  SolenoidQueueHandle = osMessageQueueNew (16, sizeof(uint16_t), &SolenoidQueue_attributes);

  /* creation of UserQueue */
  UserQueueHandle = osMessageQueueNew (16, sizeof(uint16_t), &UserQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of XbeeTask */
  XbeeTaskHandle = osThreadNew(StartXbeeTask, NULL, &XbeeTask_attributes);

  /* creation of UserTask */
  UserTaskHandle = osThreadNew(StartUserTask, NULL, &UserTask_attributes);

  /* creation of SolenoidTask */
  SolenoidTaskHandle = osThreadNew(StartSolenoidTask, NULL, &SolenoidTask_attributes);

  /* creation of WeatherTask */
  WeatherTaskHandle = osThreadNew(StartWeatherTask, NULL, &WeatherTask_attributes);

  /* creation of FlowTask */
  FlowTaskHandle = osThreadNew(StartFlowTask, NULL, &FlowTask_attributes);

  /* creation of ProcessingTask */
  ProcessingTaskHandle = osThreadNew(StartProcessingTask, NULL, &ProcessingTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while(1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LD2_Pin|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0 PC1 PC2 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : USART_TX_Pin USART_RX_Pin */
  GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LD2_Pin PA8 PA9 PA10
                           PA11 PA12 */
  GPIO_InitStruct.Pin = LD2_Pin|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB13 PB14 PB15 PB4
                           PB5 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PC6 PC7 PC8 PC9
                           PC10 PC11 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PD2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */
void commandToLCD(void)
{
	HAL_Delay(20);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);//RS low
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//Enable 8 bit data, 2 display lines
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2//letter font, 1 = 5x11, 0 = 5x8
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3//number of lines, 1 = 2, 0 = 1
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4//interface bit length, 1 = 8bit, 0 = 4bit
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);//E low
	HAL_Delay(5);



	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0//cursor blinking on = 1	//Enable Display, Cursor, Blink
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1//cursor on = 1
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2//display on = 1
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);//E low
	HAL_Delay(5);


	clear();


	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//Set Move Cursor Right
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2//right
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
	HAL_Delay(5);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);//R/W high
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11) == 1)
	{}
}
void printPassword(void)
{

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	letter('P');
	letter('a');
	letter('s');
	letter('s');
	letter('w');
	letter('o');
	letter('r');
	letter('d');
	letter(':');
}
void line1(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);//RS low
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//Set DDRAM to start of line 1
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1);//D7

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);//E low
	HAL_Delay(5);
}
void line2(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);//RS low
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//Set DDRAM to start of line 2
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1);//D7

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);//E low
	HAL_Delay(5);
}
void clear()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);//RS low
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//Home and clear LCD
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
	HAL_Delay(5);
}
void correct()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	letters(C);
	letters(o);
	letters(r);
	letters(r);
	letters(e);
	letters(c);
	letters(t);
	letters('!');
}
void getVal(int max)
{
	count = 0;
	while(count<max)
	{

	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 1);//ROW1

	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)//COL1
	  {
		  letters(1);

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 1;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)//COL2
	  {
		  letters(2);

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 2;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)//COL3
	  {
		  letters(3);

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 3;
		  count++;
	  }
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 0);//ROW1
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 1);//ROW2

	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)//COL1
	  {
		  letters(4);

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 4;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)//COL2
	  {
		  letters(5);

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 5;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)//COL3
	  {
		  letters(6);

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 6;
		  count++;
	  }

	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 0);//ROW2
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, 1);//ROW3

	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)//COL1
	  {
		  letters(7);

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 7;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)//COL2
	  {
		  letters(8);

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 8;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)//COL3
	  {
		  letters(9);

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 9;
		  count++;
	  }

	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, 0);//ROW3
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, 1);//ROW4

	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)//COL1
	  {
		  letters('*');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 10;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)//COL2
	  {
		  letters(0);

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 0;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)//COL3
	  {
		  letters('#');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)
		  {}
		  HAL_Delay(100);
		  val[count] = 11;
		  count++;
	  }

	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, 0);//ROW3
	}
}
void wrongPass(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	letters(W);
	letters(r);
	letters(o);
	letters(n);
	letters(g);
	letters(' ');
	letter(P);
	letter(a);
	letter(s);
	letter(s);
	letter(w);
	letter(o);
	letter(r);
	letter(d);
}
void green(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	letters(G);
	letters(r);
	letters(e);
	letters(e);
	letters(n);
	letters(' ');
	letters(1);
	letters('-');
	letters(3);
	letters(':');

	getVal(1);
}

void timer(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low

	letters(T);
	letters(i);
	letters(m);
	letters(e);
	letters(' ');
	letters(0);
	letters(0);
	letters('-');
	letters(6);
	letters(0);
	letters(m);
	letters(i);
	letters(n);
	letters(':');
	getVal(2);
}

void quit(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low

	letters(Q);
	letters(u);
	letters(i);
	letters(t);
	letters('?');
	letters(' ');
	letters(y);
	letters(e);
	letters(s);
	letters('-');
	letters(1);
	letters(' ');
	letters(n);
	letters(o);
	letters('-');
	letters(0);

	line2();
	getVal(1);
	val[6] = val[0];
}
void onOffTime(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	letters(0);
	letters('-');
	letters(O);
	letters(n);
	letters('/');
	letters(O);
	letters(f);
	letters(f);
	letters(' ');
	letters(1);
	letters('-');
	letters(T);
	letters(i);
	letters(m);
	letters(e);
	letters(r);

	line2();
	getVal(1);
}
void onOff(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	letters(0);
	letters('-');
	letters(O);
	letters(n);
	letters(' ');
	letters(1);
	letters('-');
	letters(O);
	letters(f);
	letters(f);
	letters(':');

	getVal(1);
}

void setSolenoids(int grn, int state)
{
	if(grn == 1)
	{
		if(state == 0)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
		}
		else if(state == 1)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
		}
	}
	else if(grn == 2)
	{
		if(state == 0)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
		}
		else if(state == 1)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
		}
	}
	else if(grn == 3)
	{
		if(state == 0)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);
		}
		else if(state == 1)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);
		}
	}
}
void flow (void)
{
	uint32_t tickstart = HAL_GetTick();
	uint32_t wait = 1000;
	uint32_t F1,F2,F3;
	uint32_t C1=0;
	uint32_t C2=0;
	uint32_t C3=0;
	uint32_t L1 =0;
	uint32_t L2 =0;
	uint32_t L3 =0;

	/* Add a freq to guarantee minimum wait */
	if (wait < HAL_MAX_DELAY)
	{
	wait += (uint32_t)(uwTickFreq);
	}

	while ((HAL_GetTick() - tickstart) < wait)
	{
		F1 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2);
		F2 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1);
		F3 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
		if(F1 == 1 && F1!=L1)
		{
			C1++;
		}
		if(F2 == 1 && F2!=L2)
		{
			C2++;
		}
		if(F3 == 1 && F3!=L3)
		{
			C3++;
		}
		L1=F1;
		L2=F2;
		L3=F3;

	}

	//C1= C1*60;



}

void uartInterruptInit(uint8_t length)
{
	//has to stay with main (the file where the "UART_HandleTypeDef huart3;" is)
	HAL_UART_Receive_IT(&huart3, &uartBufferRX[0], length);

	return;
}

void uartTransmit(uint8_t *buffer, uint8_t length)
{
	//has to stay with main (the file where the "UART_HandleTypeDef huart3;" is)
	HAL_UART_Transmit(&huart3, buffer, length, 1);

	return;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart)
{
	//has to stay with main (the file where the "UART_HandleTypeDef huart3;" is)
	if (uartBufferRX[0] == 0x7E)
	{
		switch (uartBufferRX[3])
		{
		case 0x92:
			processIO(uartBufferRX);
			break;

		case 0x97:
			processATResponse(uartBufferRX);
			break;

		default://if it wasnt an expected data type just throw it out
			uartInterruptInit(26);
			break;
		}
	}



	return;
}
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartXbeeTask */
/**
  * @brief  Function implementing the XbeeTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartXbeeTask */
void StartXbeeTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
	initializeNodes();
	uartInterruptInit(26);
    osDelay(1);
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartUserTask */
/**
* @brief Function implementing the UserTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartUserTask */
void StartUserTask(void *argument)
{
  /* USER CODE BEGIN StartUserTask */
	commandToLCD();

  while(1)
  {
	  val[6] = 0;
	  clear();
	  printPassword();
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 0);//ROW1
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 0);//ROW2
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, 0);//ROW3
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, 0);//ROW4

	  getVal(4);
	  if(val[0] == 1)
	  {
		  if(val[1] == 2)
		  {
			  if(val[2] == 3)
			  {
				  if(val[3] == 4)
				  {
					  clear();
					  line1();
					  correct();
					  HAL_Delay(2000);
					  while(val[6] == 0)
					  {
						  commandToLCD();
						  onOffTime();
						  if(val[0] == 0)
						  {
							  commandToLCD();
							  green();
							  indc = val[0];///do something with val[0] aka green #
							  line2();
							  onOff();
							  onoff = val[0];///do something with val[0]
							  setSolenoids(indc, onoff);
							  clear();
							  quit();
							  commandToLCD();
						  }

						  else if(val[0] == 1)
						  {

								  commandToLCD();
								  green();
								  indc = val[0];///do something with val[0] aka green #
								  line2();
								  timer();
								  ///do something with val[0] and val[1]
								  flow();
								  clear();
								  quit();
								  commandToLCD();
						  }
					  }
				  }
				  else
				  {
					  line2();
					  wrongPass();
					  HAL_Delay(2000);
				  }
			  }
			  else
			  {
				  line2();
				  wrongPass();
				  HAL_Delay(2000);
			  }
		  }
		  else
		  {
			  line2();
			  wrongPass();
			  HAL_Delay(2000);
		  }
	  }
	  else
	  {
		  line2();
		  wrongPass();
		  HAL_Delay(2000);
	  }

  }
  /* USER CODE END StartUserTask */
}

/* USER CODE BEGIN Header_StartSolenoidTask */
/**
* @brief Function implementing the SolenoidTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartSolenoidTask */
void StartSolenoidTask(void *argument)
{
  /* USER CODE BEGIN StartSolenoidTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartSolenoidTask */
}

/* USER CODE BEGIN Header_StartWeatherTask */
/**
* @brief Function implementing the WeatherTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartWeatherTask */
void StartWeatherTask(void *argument)
{
  /* USER CODE BEGIN StartWeatherTask */
  /* Infinite loop */
  for(;;)
  {
		HAL_TIM_Base_Start(&htim2);
		uint32_t period; //frequency;
		uint32_t RH1 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0);
		uint32_t tickstart = __HAL_TIM_GET_COUNTER(&htim2);


		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == RH1)
		{}
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) != RH1)
		{}
		period =  __HAL_TIM_GET_COUNTER(&htim2) - tickstart;
		//frequency = 10000/period;
    osDelay(1);
  }
  /* USER CODE END StartWeatherTask */
}

/* USER CODE BEGIN Header_StartFlowTask */
/**
* @brief Function implementing the FlowTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartFlowTask */
void StartFlowTask(void *argument)
{
  /* USER CODE BEGIN StartFlowTask */
  /* Infinite loop */
  for(;;)
  {

    osDelay(1);
  }
  /* USER CODE END StartFlowTask */
}

/* USER CODE BEGIN Header_StartProcessingTask */
/**
* @brief Function implementing the ProcessingTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartProcessingTask */
void StartProcessingTask(void *argument)
{
  /* USER CODE BEGIN StartProcessingTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartProcessingTask */
}

 /**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM4 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM4) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
