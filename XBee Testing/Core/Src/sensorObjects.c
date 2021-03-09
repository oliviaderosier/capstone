/*
 * sensorObjects.c
 *
 *  Created on: Mar. 2, 2021
 *      Author: Colton Moore
 */
#include "sensorObjects.h"

void initializeNodes()
{
	//Address Arrays
	uint8_t BlueAddress[] 	= {0x00, 0x13, 0xA2, 0x00, 0x41, 0xCF, 0x0B, 0xD1};
	uint8_t GreenAddress[] 	= {0x00, 0x13, 0xA2, 0x00, 0x41, 0xCF, 0x0B, 0xDD};
	uint8_t RedAddress[] 	= {0x00, 0x13, 0xA2, 0x00, 0x41, 0xCF, 0x0C, 0xA6};

	uint8_t i = 0;
	for (i = 0; i<32; i++)
	{
		fairways[i].battery 	= 0;
		fairways[i].capacative	= 0;
		fairways[i].resistive 	= 0;
		fairways[i].temperature	= 0;
	}

	for (i= 0; i<8; i++)
	{
		fairways[0].address[i] = BlueAddress[i];
		fairways[1].address[i] = GreenAddress[i];
		fairways[2].address[i] = RedAddress[i];
	}

	return;
}

//Process Data
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void processATResponse(uint8_t *ATResponse)
{
	int nodeNum = 0;

	for (nodeNum = 0; nodeNum<36; nodeNum++) //to cycle through the 36 available nodes.
		{
			int match = 1;
			//Compare the address in the API Frame to the address of our known nodes.
			//the address bytes in the API frame are 5-12
			//if we find a different byte, we know its the wrong address and do not have a match
			for (int j = 0; j<8; j++)
			{
				if (ATResponse[j+5] != (fairways[nodeNum]).address[j])
				{
					match = 0;
					break; //exit the loop, its not this node
				}
			}

			if (match == 1)
			{
				//get which data type it is
				//no longer need the first "IF" because the temp is now coming from an ADC
				//we will keep in so we could add ambient field temp in the future.
				if (ATResponse[15] == 0x54 && ATResponse[16] == 0x50) //if the AT command was "TP"
				{
					fairways[nodeNum].temperature = ATResponse[18] *256 + ATResponse[19]; //store temp data then request battery data
					HAL_UART_Receive_IT(&huart3, &uartBufferRX[0], 21);
					sendBattRequest(nodeNum);
				}
				else if (ATResponse[15] == 0x25 && ATResponse[16] == 0x56) //if the AT command was "%V"
				{
					fairways[nodeNum].battery = ATResponse[18]*256 + ATResponse[19];
					HAL_UART_Receive_IT(&huart3, &uartBufferRX[0], 26);//Listen for IO data becasue we should have both requests received
				}
				else
				{	//if we got an unexpected AT Command Type, give up and try again next time data is transmitted
					//uartInterruptInit(26);
					HAL_UART_Receive_IT(&huart3, &uartBufferRX[0], 26);
				}

				nodeNum = 255; //break the loop. Break would work too but this explicitly breaks the correct loop if i move things.
			}
		}

  return;
}

void processIO(uint8_t *ioData)
{
	uint16_t sensorResistive 	= 0;
	uint16_t sensorCapacative 	= 0;
	uint16_t sensorTemperature 	= 0;
	uint8_t	 match = 0;

	if(!verifyChecksum(ioData))
	{
		return;//include an error report here if time permits
	}
	else
	{
		sensorResistive 	= ioData[19]*256 + ioData[20]; //ADC0
		sensorCapacative	= ioData [21]*256 + ioData[22];//ADC1
		sensorTemperature 	= ioData [23]*256 + ioData[24];//ADC2
	}

	//Determine which sensor it belongs to
	//get the address, if it exists, put the data into it
	//if the addres doesnt already exist then make a new object to put data into
	//for now we will just use the three that we have
	uint8_t nodeNumber = 0;
	for (nodeNumber = 0; nodeNumber<36; nodeNumber++) //to cycle through the 36 available nodes.
	{
		match = 1;
		//Compare the address in the API Frame to the address of our known nodes.
		//the address bytes in the API frame are 5-12
		//if we find a different byte, we know its the wrong address and do not have a match
		for (int j = 0; j<8; j++)
		{
			if (ioData[j+4] != (fairways[nodeNumber]).address[j])
			{
				match = 0;
				break;//it is not this nodeNumer (j value)
			}
		}

		if (match == 1)
		{
			fairways[nodeNumber].resistive		= sensorResistive;
			fairways[nodeNumber].capacative		= sensorCapacative;
			fairways[nodeNumber].temperature	= sensorTemperature;

			break;
			//i = 37; //break the loop. Break would work too but this explicitly breaks the correct loop if i move things.
		}
	}
	//__HAL_UART_CLEAR_FLAG(&huart3, UART_FLAG_TC);

	HAL_UART_Receive_IT(&huart3, &uartBufferRX[0], 21);
	sendBattRequest(nodeNumber);

  return;
}

//Send Data Requests
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sendBattRequest(uint8_t nodeNumber)
{
	uartBufferTX[0] = 0x7E; //startDelim
	uartBufferTX[1] = 0x00; //length byte 1
	uartBufferTX[2] = 0x0F; //length byte 2
	uartBufferTX[3] = 0x17; //Frame Type
	uartBufferTX[4] = 0x01; //Frame ID
	uartBufferTX[5] = 	fairways[nodeNumber].address[0]; //start of 64bit address
	uartBufferTX[6] = 	fairways[nodeNumber].address[1];
	uartBufferTX[7] = 	fairways[nodeNumber].address[2];
	uartBufferTX[8] = 	fairways[nodeNumber].address[3];
	uartBufferTX[9] = 	fairways[nodeNumber].address[4];
	uartBufferTX[10] =	fairways[nodeNumber].address[5];
	uartBufferTX[11] = 	fairways[nodeNumber].address[6];
	uartBufferTX[12] = 	fairways[nodeNumber].address[7]; //last of 64bit address
	uartBufferTX[13] = 0xFF;//Start of 16 bit address
	uartBufferTX[14] = 0xFE;//End of 16 bit address
	uartBufferTX[15] = 0x02;//Command Options - 0x02 means apply
	uartBufferTX[16] = 0x25;//AT Command Byte 1 - 0x25 is '%'
	uartBufferTX[17] = 0x56;//AT Command Byte 2 - 0x56 is 'V'
	uartBufferTX[18] = generateChecksum(uartBufferTX);//Checksum (as calculated by XCTU)

	HAL_UART_Receive_IT(&huart3, &uartBufferRX[0], 19);
	return;
}

void sendTempRequest(uint8_t nodeNumber)
{
	//no longer needed within the scope of the project but kept so we could add ambient air temperature readings
	//if we wanted to.
	uartBufferTX[0] = 0x7E; //startDelim
	uartBufferTX[1] = 0x00; //length byte 1
	uartBufferTX[2] = 0x0F; //length byte 2
	uartBufferTX[3] = 0x17; //Frame Type
	uartBufferTX[4] = 0x01; //Frame ID
	uartBufferTX[5] = 	fairways[nodeNumber].address[0]; //start of 64bit address
	uartBufferTX[6] = 	fairways[nodeNumber].address[1];
	uartBufferTX[7] = 	fairways[nodeNumber].address[2];
	uartBufferTX[8] = 	fairways[nodeNumber].address[3];
	uartBufferTX[9] = 	fairways[nodeNumber].address[4];
	uartBufferTX[10] =	fairways[nodeNumber].address[5];
	uartBufferTX[11] = 	fairways[nodeNumber].address[6];
	uartBufferTX[12] = 	fairways[nodeNumber].address[7]; //last of 64bit address
	uartBufferTX[13] = 0xFF;//Start of 16 bit address
	uartBufferTX[14] = 0xFF;//End of 16 bit address
	uartBufferTX[15] = 0x02;//Command Options - 0x02 means apply
	uartBufferTX[16] = 0x54;//AT Command Byte 1 - 0x54 is 'T'
	uartBufferTX[17] = 0x50;//AT Command Byte 2 - 0x50 is 'P'
	uartBufferTX[18] = generateChecksum(uartBufferTX);//passes the address of the struct

	HAL_UART_Receive_IT(&huart3, &uartBufferRX[0], 19);
	return;
}


//Checksum Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t verifyChecksum(uint8_t *ioData)
{
	uint16_t lengthOfData = ioData[1] * 256 + ioData[2]; //this value should always be 17
	uint16_t checkSumCompare = 0; //calculate the check sum and see if it matches the value recieved

	/* to verify the checksum:
	 * Add all bytes including the checksum; do not include the delimiter and length.
	 * If the checksum is correct, the last two digits on the far right of the sum equal 0xFF.
	 */

	for (int i = 0; i<=lengthOfData; i++)
	{	//i<=lengthOfData includes checksum value, as opposed to i<lengthOfData which does not
		checkSumCompare += ioData[i+3]; //i+3 becasue we skip the delim and length values
	}

	if ((checkSumCompare & 0xFF) == 0xFF) //clears all bits except lowest 8 then compares
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

uint8_t generateChecksum(uint8_t *frame)
{
	/*
	 * Add all bytes of the packet, except the start delimiter 0x7E and the length (the second and third bytes).
	 * Keep only the lowest 8 bits from the result.
   	 * Subtract this quantity from 0xFF.
   	 */

	uint16_t length = frame[1]*256 + frame[2];
	uint8_t i = 0;
	uint16_t sum= 0;

	for (i=0; i<length; i++)
	{
		sum += frame[i+3];
		//sum = sum & 0xFF;//we only need the last two bits in the end
		//this clears off the high numbers that we dont need so we can use
		//a smaller data type
	}

	return (0xFF - sum);
}

