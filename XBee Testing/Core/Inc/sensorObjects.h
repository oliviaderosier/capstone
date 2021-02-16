/*
 * sensorObjects.h
 *
 *  Created on: Jan 27, 2021
 *      Author: colto
 */

#ifndef INC_SENSOROBJECTS_H_
#define INC_SENSOROBJECTS_H_

/*
 * Frames to send:
 * Remote AT Command:
 *   START_DELIM then LENGTH then FRAME TYPE then ADDRESS then DEST_ADDRESS_16_BIT then COMMAND OPTIONS then AT COMMAND then CHECKSUM
 *   START_DELIM->REMOTE_TP_REQUEST_LENGTH->FRAMETYPE_REMOTE_AT->BLUE_NODE->DEST_ADDRESS_16BIT->OPTION_APPLY->AT_TP then calc checksum
 * */

//Address Definitions
#define BLUE_NODE 	0x0013A20041CF0BD1
#define GREEN_NODE 	0x0013A20041CF0BDD
#define RED_NODE 	0x0013A20041CF0CA6

//Addres Arrays
uint8_t BlueAddress[] 	= {0x00, 0x13, 0xA2, 0x00, 0x41, 0xCF, 0x0B, 0xD1};
uint8_t GreenAddress[] 	= {0x00, 0x13, 0xA2, 0x00, 0x41, 0xCF, 0x0B, 0xDD};
uint8_t RedAddress[] 	= {0x00, 0x13, 0xA2, 0x00, 0x41, 0xCF, 0x0C, 0xA6};

//Hex codes for AT Commands
#define START_DELIM			0x7E
#define DEST_ADDRESS_16BIT	0xFFFE

//Frame Types
#define FRAMETYPE_LOCAL_AT	0x08	//AT Command
#define FRAMETYPE_REMOTE_AT	0x17	//Remote AT Command

//Typical request length
#define REMOTE_TP_REQUEST_LENGTH	0x000F //15

//Common AT commands
#define AT_TP	0x5054 //TP
#define AT_BV	0x2556 //%V

//Remote Command Options
#define OPTION_APPLY	0x02 //apply changes

typedef struct sensorNode {
	uint8_t address[8];

	uint16_t resistive;
	uint16_t capacative;
	uint16_t battery;
	uint16_t temperature;


};

struct sensorNode fairways[36];

uint8_t verifyChecksum(uint8_t *ioData)
{
	uint16_t lengthOfData = ioData[1] * 256 + ioData[2]; //this value should always be 17
	uint16_t checkSumCompare = 0; //calculate the check sum and see if it matches the value recieved

	/* to verify the checksum:
	 * Add all bytes including the checksum; do not include the delimiter and length.
	 * If the checksum is correct, the last two digits on the far right of the sum equal 0xFF.
	 */

	for (int i = 3; i<=lengthOfData; i++) //start at i=3 so we do not include delimiter and length
	{	//i<=lengthOfData includes checksum value
		checkSumCompare += ioData[i];
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

void processIO(uint8_t *ioData)
{
	uint16_t sensorResistive 	= 0;
	uint16_t sensorCapacative 	= 0;
	uint8_t	 match = 0;

	if(!verifyChecksum(ioData))
	{
		return;//include an error report here if time permits
	}
	else
	{
		sensorResistive = ioData[19]*256 + ioData[20]; //ADC0
		sensorCapacative = ioData [21]*256 + ioData[22];//ADC1
	}

	//Determine which sensor it belongs to
	//get the address, if it exists, put the data into it
	//if the addres doesnt already exist then make a new object to put data into
	//for now we will just use the three that we have
	for (int i = 0; i<36; i++) //to cycle through the 36 available nodes.
	{
		match = 1;
		//Compare the address in the API Frame to the address of our known nodes.
		//the address bytes in the API frame are 5-12
		//if we find a different byte, we know its the wrong address and do not have a match
		for (int j = 0; j<8; j++)
		{
			if (ioData[j+5] != (fairways[i]).address[j])
			{
				match = 0;
			}
		}

		if (match == 1)
		{
			fairways[i].resistive 	= sensorResistive;
			fairways[i].capacative 	= sensorCapacative;

			i = 37; //break the loop. Break would work too but this explicitly breaks the correct loop if i move things.
		}
	}


  return;
}

void processATResponse()
{


  return;
}



#endif /* INC_SENSOROBJECTS_H_ */
