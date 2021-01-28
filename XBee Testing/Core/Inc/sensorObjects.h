/*
 * sensorObjects.h
 *
 *  Created on: Jan 27, 2021
 *      Author: colto
 */

#ifndef INC_SENSOROBJECTS_H_
#define INC_SENSOROBJECTS_H_

struct sensorNode {
	uint8_t resistive;
	uint8_t capacative;
	uint8_t battery;
	uint8_t temperature;

}

#endif /* INC_SENSOROBJECTS_H_ */
