/*
 * sbus.h
 *
 *  Created on: 14-Jul-2026
 *      Author: priya
 */

#ifndef INC_SBUS_H_
#define INC_SBUS_H_
#include "main.h"

void updateSbusPacket(uint16_t *channel, uint8_t num_of_channels);
extern uint8_t sbusPacket[25];


#endif /* INC_SBUS_H_ */
