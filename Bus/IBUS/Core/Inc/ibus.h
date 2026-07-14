/*
 * ibus.h
 *
 *  Created on: 14-Jul-2026
 *      Author: priya
 */

#ifndef INC_IBUS_H_
#define INC_IBUS_H_
#include "main.h"
#include <stdint.h>

void updateIbusPacket(uint16_t *channel, uint8_t num_of_channel);
extern uint8_t ibusPacket[32];



#endif /* INC_IBUS_H_ */
