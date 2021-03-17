/*
 * Letters.c
 *
 *  Created on: Mar.6, 2021
 *      Author: Austin Waldron
 *
 * Description: This file will have the code needed to print letters to my LCD
 *	screen as many are repeats and they take 11 lines of code each.
 *
 */

#include "Letters.h"

void letter(char L)
{
	if(L == ':')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//:
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '-')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//-
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == ' ')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//space
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '/')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	// /
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '!')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//!
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
	}
	if(L == '?')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//?
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '*')
	{
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//*
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
	  HAL_Delay(2);
	}
	if(L == '#')
	{
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//#
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		  HAL_Delay(2);
	}
	if(L == 'a')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//a
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'C')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//C
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'c')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//c
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'd')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//d
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'e')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//e
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'f')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//f
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'G')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//G
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'g')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//g
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'i')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//i
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'm')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//m
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'n')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//n
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'O')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//O
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'o')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//o
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'P')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//P
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'Q')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//Q
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'r')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//r
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 's')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//s
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'T')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//T
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 't')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//t
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'u')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//u
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'W')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//W
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'w')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//w
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == 'y')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//y
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '0')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//0
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '1')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '2')
	{
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//2
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
	}
	if(L == '3')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//3
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '4')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//4
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '5')
	{
		 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

				  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//5
				  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
				  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
				  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '6')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//6
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '7')
	{
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//7
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);//D1
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);//D2
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);//D3
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L == '8')
	{
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);//D0	//8
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}
	if(L =='9')
	{
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);//E high

		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);//D0	//9
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);//D1
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//D2
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);//D3
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);//D4
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);//D5
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);//D6
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);//D7

		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //E low
		HAL_Delay(2);
	}

}
