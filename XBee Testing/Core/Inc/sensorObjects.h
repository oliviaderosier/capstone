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

struct sensorNode {
	uint8_t resistive	= 0;
	uint8_t capacative	= 0;
	uint8_t battery		= 0;
	uint8_t temperature	= 0;

};

void processIO()
{
  return;
}

void processTempRequest()
{
  return;
}

#endif /* INC_SENSOROBJECTS_H_ */
