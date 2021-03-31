/*
 * sensorObjects.h
 *
 *  Created on: Jan 27, 2021
 *      Author: colto
 */

#ifndef INC_SENSOROBJECTS_H_
#define INC_SENSOROBJECTS_H_

#include "main.h"
#include "math.h"
//Function Prototypes
void sendBattRequest(uint8_t);
void sendTempRequest(uint8_t);

void processATResponse(uint8_t*);
void processIO(uint8_t*);

void initializeNodes(void);

uint8_t verifyChecksum(uint8_t*);
uint8_t generateChecksum(uint8_t *frame);

void calcTemp(uint8_t, uint8_t, uint8_t*);
void calcPercent(uint8_t, uint8_t, uint8_t*);



void sensorToGateway(uint8_t nodeNumber);

//Global Variables
uint8_t uartBufferRX[50];
uint8_t uartBufferTX[50];

//Remote Command Options
#define OPTION_APPLY	0x02 //apply changes

struct sensorNode {
	uint8_t address[8];

	uint8_t resistive[2];
	uint8_t capacative[2];
	uint8_t battery[2];
	uint8_t temperature[3];
};

struct sensorNode fairways[36];

#endif /* INC_SENSOROBJECTS_H_ */
