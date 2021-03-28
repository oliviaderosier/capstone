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

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;
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
/* Definitions for WebsiteTask */
osThreadId_t WebsiteTaskHandle;
const osThreadAttr_t WebsiteTask_attributes = {
  .name = "WebsiteTask",
  .priority = (osPriority_t) osPriorityAboveNormal7,
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
/* Definitions for WebsiteQueue */
osMessageQueueId_t WebsiteQueueHandle;
const osMessageQueueAttr_t WebsiteQueue_attributes = {
  .name = "WebsiteQueue"
};
/* Definitions for ProcessQueue */
osMessageQueueId_t ProcessQueueHandle;
const osMessageQueueAttr_t ProcessQueue_attributes = {
  .name = "ProcessQueue"
};
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM1_Init(void);
void StartXbeeTask(void *argument);
void StartUserTask(void *argument);
void StartSolenoidTask(void *argument);
void StartWeatherTask(void *argument);
void StartFlowTask(void *argument);
void StartProcessingTask(void *argument);
void StartWebsiteTask(void *argument);

/* USER CODE BEGIN PFP */
void commandToLCD(void);
void printPassword(void);
void line1(void);
void line2(void);
void clear(void);
void correct(void);
int getVal(void);
void wrongPass(void);
void green(void);
void timer(void);
void quit(void);
void onOffTime(void);
void onOff(void);
void error(void);
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
  MX_USART1_UART_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
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
  FlowQueueHandle = osMessageQueueNew (8, sizeof(uint16_t), &FlowQueue_attributes);

  /* creation of WeatherQueue */
  WeatherQueueHandle = osMessageQueueNew (8, sizeof(uint16_t), &WeatherQueue_attributes);

  /* creation of SolenoidQueue */
  SolenoidQueueHandle = osMessageQueueNew (8, sizeof(uint16_t), &SolenoidQueue_attributes);

  /* creation of UserQueue */
  UserQueueHandle = osMessageQueueNew (8, sizeof(uint16_t), &UserQueue_attributes);

  /* creation of WebsiteQueue */
  WebsiteQueueHandle = osMessageQueueNew (8, sizeof(uint16_t), &WebsiteQueue_attributes);

  /* creation of ProcessQueue */
  ProcessQueueHandle = osMessageQueueNew (8, sizeof(uint16_t), &ProcessQueue_attributes);

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

  /* creation of WebsiteTask */
  WebsiteTaskHandle = osThreadNew(StartWebsiteTask, NULL, &WebsiteTask_attributes);

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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_15;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

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
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

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
  huart3.Init.BaudRate = 9600;
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
  HAL_GPIO_WritePin(GPIOA, LD2_Pin|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_11
                          |GPIO_PIN_12, GPIO_PIN_RESET);

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

  /*Configure GPIO pins : LD2_Pin PA7 PA8 PA11
                           PA12 */
  GPIO_InitStruct.Pin = LD2_Pin|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_11
                          |GPIO_PIN_12;
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
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);//D4//interface bit length, 1 = 8bit, 0 = 4bit
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
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);//D4
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
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);//D4
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
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);//D4
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
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);//D4
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
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);//D4
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
	letter('C');
	letter('o');
	letter('r');
	letter('r');
	letter('e');
	letter('c');
	letter('t');
	letter('!');
}
int getVal(void)
{
	int count = 0;
	int val=0;
	while(count<1)
	{

	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 1);//ROW1

	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)//COL1
	  {
		  letter('1');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)
		  {}
		  HAL_Delay(100);
		  val = 1;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)//COL2
	  {
		  letter('2');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)
		  {}
		  HAL_Delay(100);
		  val = 2;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)//COL3
	  {
		  letter('3');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)
		  {}
		  HAL_Delay(100);
		  val = 3;
		  count++;
	  }
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 0);//ROW1
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 1);//ROW2

	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)//COL1
	  {
		  letter('4');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)
		  {}
		  HAL_Delay(100);
		  val = 4;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)//COL2
	  {
		  letter('5');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)
		  {}
		  HAL_Delay(100);
		  val = 5;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)//COL3
	  {
		  letter('6');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)
		  {}
		  HAL_Delay(100);
		  val = 6;
		  count++;
	  }

	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 0);//ROW2
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, 1);//ROW3

	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)//COL1
	  {
		  letter('7');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)
		  {}
		  HAL_Delay(100);
		  val = 7;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)//COL2
	  {
		  letter('8');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)
		  {}
		  HAL_Delay(100);
		  val = 8;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)//COL3
	  {
		  letter('9');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)
		  {}
		  HAL_Delay(100);
		  val = 9;
		  count++;
	  }

	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, 0);//ROW3
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, 1);//ROW4

	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)//COL1
	  {
		  letter('*');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == 1)
		  {}
		  HAL_Delay(100);
		  val = 10;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)//COL2
	  {
		  letter('0');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1)
		  {}
		  HAL_Delay(100);
		  val = 0;
		  count++;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)//COL3
	  {
		  letter('#');

		  while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1)
		  {}
		  HAL_Delay(100);
		  val = 11;
		  count++;
	  }

	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, 0);//ROW3
	}
	return val;
}
void wrongPass(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	letter('W');
	letter('r');
	letter('o');
	letter('n');
	letter('g');
	letter(' ');
	letter('P');
	letter('a');
	letter('s');
	letter('s');
	letter('w');
	letter('o');
	letter('r');
	letter('d');
}
void green(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	letter('G');
	letter('r');
	letter('e');
	letter('e');
	letter('n');
	letter(' ');
	letter('1');
	letter('-');
	letter('3');
	letter(':');

}

void timer(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low

	letter('T');
	letter('i');
	letter('m');
	letter('e');
	letter(' ');
	letter('0');
	letter('0');
	letter('-');
	letter('6');
	letter('0');
	letter('m');
	letter('i');
	letter('n');
	letter(':');

}

void quit(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low

	letter('Q');
	letter('u');
	letter('i');
	letter('t');
	letter('?');
	letter(' ');
	letter('y');
	letter('e');
	letter('s');
	letter('-');
	letter('1');
	letter(' ');
	letter('n');
	letter('o');
	letter('-');
	letter('0');
}
void onOffTime(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	letter('0');
	letter('-');
	letter('O');
	letter('n');
	letter('/');
	letter('O');
	letter('f');
	letter('f');
	letter(' ');
	letter('1');
	letter('-');
	letter('T');
	letter('i');
	letter('m');
	letter('e');
	letter('r');
	line2();
}
void onOff(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	letter('0');
	letter('-');
	letter('O');
	letter('n');
	letter(' ');
	letter('1');
	letter('-');
	letter('O');
	letter('f');
	letter('f');
	letter(':');

}
void error(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low

	letter('E');
	letter('r');
	letter('r');
	letter('o');
	letter('r');
	letter(',');
	letter(' ');
	letter('I');
	letter('n');
	letter('v');
	letter('a');
	letter('l');
	letter('i');
	letter('d');

	line2();

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);//RS high
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);//R/W low
	letter('N');
	letter('u');
	letter('m');
	letter('b');
	letter('e');
	letter('r');
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
	initializeNodes();
//	HAL_UART_Receive(&huart3, &uartBufferRX[0], 26, 10);
  for(;;)
  {

	  	  if(HAL_UART_Receive(&huart3, uartBufferRX, 26, 100) == HAL_OK)
	  		  {
	  //		  HAL_UART_Transmit(&huart1, uartBufferTX, 13, 1000); // send info to Olivia when recieved
	  				//has to stay with main (the file where the "UART_HandleTypeDef huart3;" is)
	  //				if (uartBufferRX[0] == 0x7E)
	  //				{
	  //					switch (uartBufferRX[3])
	  //					{
	  //					case 0x92:
	  //						processIO(uartBufferRX);
	  //						break;
	  //
	  //					case 0x97:
	  //						processATResponse(uartBufferRX);
	  //						break;
	  //
	  //					default://if it wasnt an expected data type just throw it out
	  //						HAL_UART_Receive(&huart3, &uartBufferRX[0], 26, 1000);
	  //						break;
	  //					}
	  //				}
	    }
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

	uint16_t num[7];
	uint16_t indc, m;

  for(;;)
  {

	commandToLCD();
	printPassword();
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 0);//ROW1
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 0);//ROW2
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, 0);//ROW3
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, 0);//ROW4

	for(int i = 0; i < 4; i++)
	{
		num[i] = getVal();
	}
	if(num[0] == 2 && num[1] == 2 && num[2] == 2 && num[3] == 2)
	{
		clear();
		line1();
		correct();
		HAL_Delay(1500);
		num[6] = 0;
		while(num[6] == 0)
		{
			commandToLCD();
			onOffTime();
			num[0] = getVal();
			while(num[0]< 0 || num[0] > 1)
			{
				commandToLCD();
				error();
				HAL_Delay(1500);
				commandToLCD();
				onOffTime();
				num[0] = getVal();
			}
			if(num[0] == 0)
			{
				m = 1;
				commandToLCD();
				green();
				num[0] = getVal();
				while(num[0]< 1 || num[0] > 3)
				{
					commandToLCD();
					error();
					HAL_Delay(1500);
					commandToLCD();
					green();
					num[0] = getVal();
				}
				indc = num[0];
				line2();
				onOff();
				num[0] = getVal();
				while(num[0]< 0 || num[0] > 1)
				{
					commandToLCD();
					error();
					HAL_Delay(1500);
					commandToLCD();
					onOff();
					num[0] = getVal();
				}
				osMessageQueuePut(UserQueueHandle, &m, 1U, 0U);
				osMessageQueuePut(UserQueueHandle, &indc, 1U, 0U);//do something with green
				osMessageQueuePut(UserQueueHandle, &num[0], 1U, 0U);//do something with state
				clear();
				quit();
				num[5] = getVal();
				while(num[5]< 0 || num[5] > 1)
				{
					commandToLCD();
					error();
					HAL_Delay(1500);
					commandToLCD();
					quit();
					num[5] = getVal();
				}
			}
			else if(num[0] == 1)
			{
				m = 2;
				commandToLCD();
				green();
				num[0] = getVal();
				while(num[0]< 1 || num[0] > 3)
				{
					commandToLCD();
					error();
					HAL_Delay(1500);
					commandToLCD();
					green();
					num[0] = getVal();
				}
				indc = num[0];
				line2();
				timer();
				num[0] = getVal();
				num[1] = getVal();
				while(num[0]< 0 || num[0] > 6 || num[1]< 0 || num[1] > 9 || (num[0]==6 && num[1]!=0))
				{
					commandToLCD();
					error();
					HAL_Delay(1500);
					commandToLCD();
					timer();
					num[0] = getVal();
					num[1] = getVal();
				}
				osMessageQueuePut(UserQueueHandle, &m, 1U, 0U);
				osMessageQueuePut(UserQueueHandle, &indc, 1U, 0U);//do something with green and time
				num[2] = num[1] + (num[0] * 10);
				osMessageQueuePut(UserQueueHandle, &num[2], 1U, 0U);

				clear();
				quit();
				num[5] = getVal();
				while(num[5]< 0 || num[5] > 1)
				{
					commandToLCD();
					error();
					HAL_Delay(1500);
					commandToLCD();
					quit();
					num[5] = getVal();
				}
			}
			if(num[5] == 1)
			{
				num[6] = 5;
			}
		}
	}
	else
	{
		line2();
		wrongPass();
		HAL_Delay(2000);
	}
	osDelay(1);
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
	uint8_t input, C, in[3], Flow[3], water[3], new, L1, L2, L3;
	uint32_t timT1, timT2, timT3, timF1, timF2, timF3, timS1, timS2, timS3, temp;
	timS1 = 0;
	timS2 = 0;
	timS3 = 0;
	timT1 = 0;
	timT2 = 0;
	timT3 = 0;
	timF1 = 10;
	timF2 = 10;
	timF3 = 10;
	/* Infinite loop */

  for(;;)
  {

	  while(timT1< timF1 && timT2 < timF2 && timT3 < timF3)
	  {
		  C=0;
		  new = 0;
		  while(osMessageQueueGet(ProcessQueueHandle, &input, NULL, 0U ) == osOK)
		  {//when receiving data put it in this array
			  in[C] = input;
			  C++;
			  new = 1;
		  }
		  if(new == 1)
		  {
			  if(in[0] == 1)
			  {
				  if(in[1] == 0)
				  {
					  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);
					  new = 0;
				  }
				  else if(in[1] == 1)
				  {
					  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);
					  new = 0;
				  }
				  timF1 = in[2];
				  timS1 = __HAL_TIM_GET_COUNTER(&htim2);
			  }
			  if(in[0] == 2)
			  {
				  if(in[1] == 0)
				  {
					  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
					  new = 0;
				  }
				  else if(in[1] == 1)
				  {
					  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
					  new = 0;
				  }
				  timF2 = in[2];
				  timS2 = __HAL_TIM_GET_COUNTER(&htim2);
			  }
			  if(in[0] == 3)
			  {
				  if(in[1] == 0)
				  {
					  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
					  new = 0;
				  }
				  else if(in[1] == 1)
				  {
					  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
					  new = 0;
				  }
				  timF3 = in[2];
				  timS3 = __HAL_TIM_GET_COUNTER(&htim2);
			  }
		  }
		  while(osMessageQueueGet(FlowQueueHandle, &input, NULL, 0U ) == osOK)
		  {//when receiving data put it in this array
			  in[C] = input;
			  C++;
			  new = 1;
		  }
		  if(new == 1)
		  {
			  Flow[in[0]-1] = in[1];
			  new =0;
		  }

		  if(timF1 != 10)
		  {
			  timF1 = timF1 + timS1;
			  timS1 = 0;
			  temp = __HAL_TIM_GET_COUNTER(&htim2);
			  if(temp<L1)
				  timT1 = timT1 + temp + 65535 - L1;

			  else
				  timT1 = timT1 + (temp - L1);
			  L1 = temp;
		  }
		  if(timF2 != 10)
		  {
			  timF2 = timF2 + timS2;
			  timS2 = 0;
			  temp = __HAL_TIM_GET_COUNTER(&htim2);
			  if(temp<L2)
				  timT2 = timT2 + temp + 65535 - L2;

			  else
				  timT2 = timT2 + (temp - L2);
			  L2 = temp;
		  }
		  if(timF3 != 10)
		  {
			  timF3 = timF3 + timS3;
			  timS3 = 0;
			  temp = __HAL_TIM_GET_COUNTER(&htim2);
			  if(temp<L3)
				  timT3 = timT3 + temp + 65535 - L3;

			  else
				  timT3 = timT3 + (temp - L3);
			  L3 = temp;
		  }
	  }
	  if(timT1 >= timF1)
	  {
			water[0] = Flow[0] * timT1;
			timT1 = 0;
			timF1 = 10;
			osMessageQueuePut(SolenoidQueueHandle, &water[0], 1U, 0U);
	  }
	  if(timT2 >= timF2)
	  {
			water[1] = (Flow[1] * timT2)/65535;
			timT2 = 0;
			timF2 = 10;
			osMessageQueuePut(SolenoidQueueHandle, &water[1], 1U, 0U);
	  }
	  if(timT2 >= timF2)
	  {
			water[2] = Flow[2] * timT3;
			timT2 = 0;
			timF2 = 10;
			osMessageQueuePut(SolenoidQueueHandle, &water[2], 1U, 0U);
	  }
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
	uint16_t period[20], raw[20];
	uint16_t tickstart, tickend, totalP, totalT, a, b;
	uint16_t Pcount = 0;

	HAL_TIM_Base_Start(&htim2);

  /* Infinite loop */
  for(;;)
  {
		while(Pcount < 20)
		{
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == 0)
			{}
			tickstart = __HAL_TIM_GET_COUNTER(&htim2);
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == 1)
			{}
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == 0)
			{}
			tickend = __HAL_TIM_GET_COUNTER(&htim2);
			if(tickend > tickstart)
				period[Pcount] = tickend - tickstart;
			else
				period[Pcount] = (65535 - tickstart) + tickend;

			if(period[Pcount]< 1000)
				Pcount++;
		}

		for(int i = 0; i < 20; i++)
		{
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
			raw[i] = HAL_ADC_GetValue(&hadc1);
		}

		Pcount = 0;
		totalT = 0;
		totalP = 0;
		for(int i = 0; i < 20; i++)
		{
			totalT = totalT +raw[i];
			totalP = totalP +period[i];
		}
		totalT = totalT/20;
		totalP = totalP/20;
		if(a != totalT || b != totalP)
		{
			osMessageQueuePut(WeatherQueueHandle, &totalT, 1U, 0U);
			osMessageQueuePut(WeatherQueueHandle, &totalP, 1U, 0U);
			a = totalT;
			b = totalP;
		}
    osDelay(30);
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
  	uint16_t o[3] = {1,1,1};
  	uint16_t C[20];
  	uint16_t tickS, tickL, temp, f1, f2, f3, m;
  	uint16_t F = 0;
  	uint16_t L = 0;
  	uint16_t total = 0;
  /* Infinite loop */
  for(;;)
  {
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == 1 && o[0] == 1)
	  {
		  m = 1;
		  for(int j =0; j < 20; j++)
		  {
			  HAL_TIM_Base_Start(&htim1);
			  tickS = __HAL_TIM_GET_COUNTER(&htim1);
			  while((total-tickS)< 327675)
			  {
				  F = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2);//b7
				  if(F == 1 && F!=L)
				  {
					  C[j]++;
				  }
				  L=F;
				  temp = __HAL_TIM_GET_COUNTER(&htim1);
				  if (temp < tickL)
					  total = total + temp + (65535 - tickL);

				  else
					  total = total+ temp - tickL;

				  tickL = temp;
			  }
			  HAL_TIM_Base_Stop(&htim1);
			  total = 0;
		  }
		  for(int j =0; j < 20; j++)
		  {
			  f1 = f1 + C[j];
			  C[j] = 0;
		  }
		  f1 = f1 / 100;
		  osMessageQueuePut(FlowQueueHandle, &m, 1U, 0U);
		  osMessageQueuePut(FlowQueueHandle, &f1, 1U, 0U);
		  o[0] = 0;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == 0 && o[0] == 0)
	  {
		  o[0] = 1;
	  }


	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == 1 && o[1] == 1)
	  {
		  m = 2;
		  for(int j =0; j < 20; j++)
		  {
			  HAL_TIM_Base_Start(&htim1);
			  tickS = __HAL_TIM_GET_COUNTER(&htim1);
			  while((total-tickS)< 327675)
			  {
				  F = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1);//b5
				  if(F == 1 && F!=L)
				  {
					  C[j]++;
				  }
				  L=F;
				  temp = __HAL_TIM_GET_COUNTER(&htim1);
				  if (temp < tickL)
					  total = total + temp + (65535 - tickL);

				  else
					  total = total+ temp - tickL;

				  tickL = temp;
			  }
			  HAL_TIM_Base_Stop(&htim1);
			  total = 0;
		  }
		  for(int j =0; j < 20; j++)
		  {
			  f2 = f2 + C[j];
			  C[j] = 0;
		  }
		  f2 = f2 / 100;
		  osMessageQueuePut(FlowQueueHandle, &m, 1U, 0U);
		  osMessageQueuePut(FlowQueueHandle, &f2, 1U, 0U);
		  o[1] = 0;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == 0 && o[1] == 0)
	  {
		  o[1] = 1;
	  }


	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == 1 && o[2] == 1)
	  {
		  m = 3;
		  for(int j =0; j < 20; j++)
		  {
			  HAL_TIM_Base_Start(&htim1);
			  tickS = __HAL_TIM_GET_COUNTER(&htim1);
			  while((total-tickS)< 327675)
			  {
				  F = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2);//b4
				  if(F == 1 && F!=L)
				  {
					  C[j]++;
				  }
				  L=F;
				  temp = __HAL_TIM_GET_COUNTER(&htim1);
				  if (temp < tickL)
					  total = total + temp + (65535 - tickL);

				  else
					  total = total+ temp - tickL;

				  tickL = temp;
			  }
			  HAL_TIM_Base_Stop(&htim1);
			  total = 0;
		  }
		  for(int j =0; j < 20; j++)
		  {
			  f1 = f1 + C[j];
			  C[j] = 0;
		  }
		  f3 = f3 / 100;
		  osMessageQueuePut(FlowQueueHandle, &m, 1U, 0U);
		  osMessageQueuePut(FlowQueueHandle, &f3, 1U, 0U);
		  o[2] = 0;
	  }
	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == 0 && o[2] == 0)
	  {
		  o[2] = 1;
	  }

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
	uint16_t userOverride[3], Weather[2], Web[2];
	uint16_t input;
	uint16_t C =0;
  /* Infinite loop */
  for(;;)
  {
	  while(osMessageQueueGet(UserQueueHandle, &input, NULL, 0U ) == osOK)
	  {//when receiving data put it in this array
		  userOverride[C] = input;
		  C++;
	  }
	  C = 0;
	  while(osMessageQueueGet(WeatherQueueHandle, &input, NULL, 0U ) == osOK)
	  {//when receiving data put it in this array
		  Weather[C] = input;
		  C++;
	  }
	  C = 0;
	  while(osMessageQueueGet(WebsiteQueueHandle, &input, NULL, 0U ) == osOK)
	  {//when receiving data put it in this array
		  Web[C] = input;
		  C++;
	  }
	  C = 0;

    osDelay(1);
  }
  /* USER CODE END StartProcessingTask */
}

/* USER CODE BEGIN Header_StartWebsiteTask */
/**
* @brief Function implementing the WebsiteTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartWebsiteTask */
void StartWebsiteTask(void *argument)
{
  /* USER CODE BEGIN StartWebsiteTask */
	uint16_t water, input;
	uint8_t BufferRX[50];
  /* Infinite loop */
  for(;;)
  {
	  if(osMessageQueueGet(SolenoidQueueHandle, &input, NULL, 0U ) == osOK)
	  {//when receiving data put it in this array
		  water = water + input;
		  HAL_UART_Transmit(&huart1, water, 1, 1000);//*********also send Colton's info************
	  }
	  if(HAL_UART_Receive(&huart1, BufferRX, 5, 100) == HAL_OK)
  	  {
  		osMessageQueuePut(WebsiteQueueHandle, &BufferRX, 1U, 0U);
  	  }
    osDelay(1);
  }
  /* USER CODE END StartWebsiteTask */
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
