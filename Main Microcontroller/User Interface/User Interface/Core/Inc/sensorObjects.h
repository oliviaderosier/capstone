/*
 * sensorObjects.h
 *
 *  Created on: Jan 27, 2021
 *      Author: Colton Moore
 */

#ifndef INC_SENSOROBJECTS_H_
#define INC_SENSOROBJECTS_H_
#include "main.h"


//Function Prototypes
void sendBattRequest(uint8_t);
void sendTempRequest(uint8_t);

void processATResponse(uint8_t*);
void processIO(uint8_t*);

void initializeNodes(void);

uint8_t verifyChecksum(uint8_t*);
uint8_t generateChecksum(uint8_t *frame);

//Global Variables
uint8_t uartBufferRX[50];
uint8_t uartBufferTX[50];

//Remote Command Options
#define OPTION_APPLY	0x02 //apply changes

struct sensorNode {
	uint8_t address[8];

	uint16_t resistive;
	uint16_t capacative;
	uint16_t battery;
	uint16_t temperature;
};

struct sensorNode fairways[36];

#endif /* INC_SENSOROBJECTS_H_ */
