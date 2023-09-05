/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include<string>
#include"ssd1306.h"
#include<iostream>
#include<cstring>
#include<cmath>
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
ADC_HandleTypeDef hadc2;
ADC_HandleTypeDef hadc3;

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;
I2C_HandleTypeDef hi2c3;

TIM_HandleTypeDef htim14;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_I2C2_Init(void);
static void MX_I2C3_Init(void);
static void MX_ADC1_Init(void);
static void MX_ADC2_Init(void);
static void MX_TIM14_Init(void);
static void MX_ADC3_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

int datacheck = 0;


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
using namespace std;

double mph = 0;
double tempMph = 0;
string latGPerc;
int LatGChange = 0;
UART_HandleTypeDef* huart1ptr = &huart1;
void send_cmd(uint8_t* cmd)
{
    HAL_UART_Transmit(huart1ptr, cmd, sizeof(cmd), HAL_MAX_DELAY);
}

void read_response(char* resp, int max_len)
{
    uint8_t rec[256];
    HAL_UART_Receive(huart1ptr, rec, sizeof(rec), HAL_MAX_DELAY);
    int len = sizeof(rec);
    for (int i = 0; i < len; i++) {
       sprintf(&resp[i*2], "%02X", rec[i]); // Convert each byte to two ASCII characters
    }
    resp[len*2] = '\0'; // Add null terminator to end of string
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint16_t rawADC1, rawADC2, rawADC3, avgADC;
	char msg[10];

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  	  char myText[] = "55mph";
  	  string speedDisp;


  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  MX_I2C2_Init();
  MX_I2C3_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_TIM14_Init();
  MX_ADC3_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  ssd1306_Init(1);
  ssd1306_Init(2);
  ssd1306_Init(3);
  HAL_TIM_Base_Start_IT(&htim14);


  uint8_t kmh = 0;
  //ssd1306_Fill(Black);
  //ssd1306_UpdateScreen(1);
  //ssd1306_SetCursor(20,20);
  //retVal = ssd1306_WriteString(myText, Font_16x26, White);
  //ssd1306_UpdateScreen(1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int sel = 1;
  int temp;

  double throttle = 0;
  double tempThrottle = 0;
  string ThrottlePerc;
  string ThrottleText = "Throttle";

  double tempBraking = 0;
  double braking = 0;
  string brakingPerc;
  string brakingText = "Braking";

  string latGText = "Long. Gs";

  uint8_t cmd[256];
  char resp[256];
  uint32_t can_id;
  uint8_t can_data[8];
  uint8_t can_len;

  // Reset the ELM327
  //cmd = 'A', 'T', 'Z', '\r';


  cmd[0] = 'A';
  cmd[1] = 'T';
  cmd[2] = 'P';
  cmd[3] = 'P';
  cmd[4] = ' ';
  cmd[5] = '0';
  cmd[6] = 'C';
  cmd[7] = ' ';
  cmd[8] = 'S';
  cmd[9] = 'V';
  cmd[10] = ' ';
  cmd[11] = '0';
  cmd[12] = '8';
  send_cmd(cmd);
  read_response(resp, sizeof(resp));

  cmd[0] = 'A';
  cmd[1] = 'T';
  cmd[2] = 'P';
  cmd[3] = 'P';
  cmd[4] = ' ';
  cmd[5] = '0';
  cmd[6] = 'C';
  cmd[7] = ' ';
  cmd[8] = 'O';
  cmd[9] = 'N';
  send_cmd(cmd);
  read_response(resp, sizeof(resp));

  cmd[0] = 'A';
  cmd[1] = 'T';
  cmd[2] = 'Z';
  cmd[3] = '\r';
  send_cmd(cmd);
  read_response(resp, sizeof(resp));



  /*  POSSIBLE DELETE


  // Set the ELM327 to OBD-II mode
  cmd[0] = 'A';
  cmd[1] = 'T';
  cmd[2] = 'S';
  cmd[3] = 'P';
  cmd[4] = '0';
  send_cmd(cmd);
  read_response(resp, sizeof(resp));

  // Set the ELM327 to automatic protocol detection
  cmd[0] = 'A';
  cmd[1] = 'T';
  cmd[2] = 'S';
  cmd[3] = 'P';
  cmd[4] = '0';
  cmd[5] = '0';
  send_cmd(cmd);
  read_response(resp, sizeof(resp));

  // Set the ELM327 to automatic baud rate detection
  cmd[0] = 'A';
  cmd[1] = 'T';
  cmd[2] = 'B';
  cmd[3] = 'R';
  cmd[4] = '0';
  cmd[5] = '0';
  send_cmd(cmd);
  read_response(resp, sizeof(resp));*/


  while (1)
  {

	  /*for (int i = 0; i <= 100; i++){
		  speedDisp = to_string(i) + "mph";
		  strcpy(myText, speedDisp.c_str());
		  ssd1306_Fill(Black);
		  ssd1306_SetCursor(20,20);
		  retVal = ssd1306_WriteString(myText, Font_16x26, White);
		  ssd1306_UpdateScreen(sel);
		  sel ++;
		  if (sel == 4)
			  sel = 1;
	  }*/

	  //MONITOR FOR BRAKING
	  if (tempBraking - braking >= .5 || braking - tempBraking >= .5){
		  braking = tempBraking;
		  sel = 2;

		  temp = braking;
		  brakingPerc = to_string(temp);
		  temp = (braking * 10.0);
		  temp = temp % 10;
		  brakingPerc = brakingPerc + "." + to_string(temp) + " %";

		  ssd1306_Fill(Black);
		  ssd1306_SetCursor(25,5);
		  strcpy(myText, brakingText.c_str());
		  ssd1306_WriteString(myText, Font_11x18, White);
		  ssd1306_SetCursor(20,27);
		  strcpy(myText, brakingPerc.c_str());
		  ssd1306_WriteString(myText, Font_16x26, White);
		  ssd1306_UpdateScreen(sel);

	  }

	  //MONITOR FOR THROTTLE
	  if (tempThrottle - throttle >= .5 || throttle - tempThrottle >= .5){
		  throttle = tempThrottle;
	  	  sel = 3;

	  	  temp = throttle;
	  	  ThrottlePerc = to_string(temp);
	  	  temp = (throttle * 10.0);
	  	  temp = temp % 10;
	  	  ThrottlePerc = ThrottlePerc + "." + to_string(temp) + " %";

	  	  ssd1306_Fill(Black);
	  	  ssd1306_SetCursor(23,5);
	  	  strcpy(myText, ThrottleText.c_str());
	  	  ssd1306_WriteString(myText, Font_11x18, White);
	  	  ssd1306_SetCursor(20,27);
	  	  strcpy(myText, ThrottlePerc.c_str());
	  	  ssd1306_WriteString(myText, Font_16x26, White);
	  	  ssd1306_UpdateScreen(sel);
	  }

	  //LATERAL G FORCE MONITOR
	  //tempMPH = obd2.readVehicleSpeed();

	  if (LatGChange == 1){
	  			  // calculate lateral g force using the vehicle speed

	  	  ssd1306_Fill(Black);
	  	  ssd1306_SetCursor(20,5);
	  	  strcpy(myText, latGText.c_str());
	  	  ssd1306_WriteString(myText, Font_11x18, White);
	  	  ssd1306_SetCursor(5,25);
	  	  strcpy(myText, latGPerc.c_str());
	  	  ssd1306_WriteString(myText, Font_16x26, White);
	  	  ssd1306_UpdateScreen(1);
	  	  LatGChange = 0;
	  }


	  tempBraking = tempBraking + 0.5;


	  //tempThrottle = RxData[3];

	 // kmh = RxData[3];

	  //ADC 1
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0,GPIO_PIN_SET);
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	  rawADC1 = HAL_ADC_GetValue(&hadc1);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0,GPIO_PIN_RESET);

	  HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	  //ADC 2
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	  HAL_ADC_Start(&hadc2);
	  HAL_ADC_PollForConversion(&hadc2, HAL_MAX_DELAY);
	  rawADC2 = HAL_ADC_GetValue(&hadc2);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);

	  HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	  //ADC 3
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
	  HAL_ADC_Start(&hadc3);
	  HAL_ADC_PollForConversion(&hadc3, HAL_MAX_DELAY);
	  rawADC3 = HAL_ADC_GetValue(&hadc3);
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);

	  HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	  //COMPARE
	  avgADC = (rawADC1 + rawADC2 + rawADC3)/3;
	  rawADC1 = abs(rawADC1 - avgADC);
	  rawADC2 = abs(rawADC2 - avgADC);
	  rawADC3 = abs(rawADC3 - avgADC);

	  if (rawADC1 > rawADC2 && rawADC1 > rawADC3){ //1 is max disable it
		  cout << "Disabling 1";
	  }
	  else if (rawADC2 > rawADC1 && rawADC2 > rawADC3){ //2 is max disable it
		  cout << "Disabling 2";
	  }
	  else if (rawADC3 > rawADC1 && rawADC3 > rawADC2){ //3 is max disable it
		  cout << "Disabling 3";
	  }

	  //ReadData
	  cmd[0] = 'A';
	  cmd[1] = 'T';
	  cmd[2] = 'C';
	  cmd[3] = 'R';
	  cmd[4] = 'A';
	  cmd[5] = '7';
	  cmd[6] = 'E';
	  cmd[7] = '0';
	  send_cmd(cmd);
	  read_response(resp, sizeof(resp));
	  sscanf(resp, "%lx %x %x %x %x %x %x %x %x", &can_id, &can_data[0], &can_data[1], &can_data[2], &can_data[3], &can_data[4], &can_data[5], &can_data[6], &can_data[7]);
	  can_len = (resp[12] - '0')*2;

	  tempThrottle = can_data[3] * 100 / 255;
	  kmh = ((can_data[4] << 8) | can_data[5]) / 100;

	  /*HAL_UART_Transmit(&huart1, (uint8_t*)SpeedReq, sizeof(SpeedReq), HAL_MAX_DELAY);
	  rx_count = 8 - huart1.RxXferCount;
	  memcpy(rxdata, huart1.pRxBuffPtr, rx_count);

	  if (rxdata[1] == 0x0D){
		  kmh = rxdata[2] * 256 + rxdata[3]/100;
	  }

	  memset(rxdata, 0 , sizeof(rxdata));

	  HAL_UART_Transmit(&huart1, (uint8_t*)ThrotReq, sizeof(ThrotReq), HAL_MAX_DELAY);
	  rx_count = 8  - huart1.RxXferCount;
	  memcpy(rxdata, huart1.pRxBuffPtr, rx_count);

	  	  if (rxdata[1] == 0x11){
	  		  tempThrottle = rxdata[2] * 256 + rxdata[3]/100;
	  	  }

	  	  memset(rxdata, 0 , sizeof(rxdata));*/

	  //To read Speed and Throttle % from OBD2 Interface

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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
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

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_8B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief ADC2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC2_Init(void)
{

  /* USER CODE BEGIN ADC2_Init 0 */

  /* USER CODE END ADC2_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC2_Init 1 */

  /* USER CODE END ADC2_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc2.Instance = ADC2;
  hadc2.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc2.Init.Resolution = ADC_RESOLUTION_8B;
  hadc2.Init.ScanConvMode = DISABLE;
  hadc2.Init.ContinuousConvMode = DISABLE;
  hadc2.Init.DiscontinuousConvMode = DISABLE;
  hadc2.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc2.Init.NbrOfConversion = 1;
  hadc2.Init.DMAContinuousRequests = DISABLE;
  hadc2.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC2_Init 2 */

  /* USER CODE END ADC2_Init 2 */

}

/**
  * @brief ADC3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC3_Init(void)
{

  /* USER CODE BEGIN ADC3_Init 0 */

  /* USER CODE END ADC3_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC3_Init 1 */

  /* USER CODE END ADC3_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc3.Instance = ADC3;
  hadc3.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc3.Init.Resolution = ADC_RESOLUTION_8B;
  hadc3.Init.ScanConvMode = DISABLE;
  hadc3.Init.ContinuousConvMode = DISABLE;
  hadc3.Init.DiscontinuousConvMode = DISABLE;
  hadc3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc3.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc3.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc3.Init.NbrOfConversion = 1;
  hadc3.Init.DMAContinuousRequests = DISABLE;
  hadc3.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_10;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC3_Init 2 */

  /* USER CODE END ADC3_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief I2C3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C3_Init(void)
{

  /* USER CODE BEGIN I2C3_Init 0 */

  /* USER CODE END I2C3_Init 0 */

  /* USER CODE BEGIN I2C3_Init 1 */

  /* USER CODE END I2C3_Init 1 */
  hi2c3.Instance = I2C3;
  hi2c3.Init.ClockSpeed = 100000;
  hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C3_Init 2 */

  /* USER CODE END I2C3_Init 2 */

}

/**
  * @brief TIM14 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM14_Init(void)
{

  /* USER CODE BEGIN TIM14_Init 0 */

  /* USER CODE END TIM14_Init 0 */

  /* USER CODE BEGIN TIM14_Init 1 */

  /* USER CODE END TIM14_Init 1 */
  htim14.Instance = TIM14;
  htim14.Init.Prescaler = 7999;
  htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim14.Init.Period = 9999;
  htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM14_Init 2 */

  /* USER CODE END TIM14_Init 2 */

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
  huart1.Init.BaudRate = 115200;
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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10|GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PC10 PC11 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */

	void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
		if (htim == (&htim14)){
			  const double g = 9.81; // acceleration due to gravity in m/s^2
			  double Lat_g = 0;
			  double metersPerSec;
			  double tempMetersPerSec;
			  int temp = 0;
			  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); //HERE, MPH REPRESENTS CURRENT MPH, TEMPMPH REPRESENTS THE MPH 1 SECOND AGO.
			  if (tempMph - mph >= .25 || mph - tempMph >= .25){
			  // calculate lateral g force using the vehicle speed
				  metersPerSec = mph * .44704;
				  tempMetersPerSec = tempMph * .44704;
			  	  Lat_g = (metersPerSec - tempMetersPerSec)/g;

			  	  temp = Lat_g;
			  	  latGPerc = to_string(temp);
			  	  temp = Lat_g * 100;
			  	  temp = temp % 100;
			  	  if (temp < 10){
			  		latGPerc = latGPerc + ".0" + to_string(temp);
			  	  }
			  	  else {
			  		  latGPerc = latGPerc + "." + to_string(temp);
			  	  }

			  	  tempMph = mph;
			  	  LatGChange = 1;
			  }
		}
	}

/* USER CODE END 4 */

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
