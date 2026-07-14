/*
 * ibus.c
 *
 *  Created on: 14-Jul-2026
 *      Author: priya
 */


#include "ibus.h"
uint8_t ibusPacket[32];
void updateIbusPacket(uint16_t *channel, uint8_t num_of_channel)
{
	ibusPacket[0]=0x20;
	ibusPacket[1]=0x40;
	uint16_t checksum = 0xFFFF;
	for(int i=0; i< num_of_channel; i++)
	{
		uint16_t val = (i< num_of_channel)?channel[i]:1500;
		ibusPacket[2 + i*2] = (uint8_t)(val & 0xFF);
		ibusPacket[2 + i*2+1] = (uint8_t)((val >> 8) & 0xFF);
	}
	for (int i=0; i<30; i++)
	{
		checksum -= ibusPacket[i];
	}
	ibusPacket[30] = (uint8_t)(checksum & 0xFF);
	ibusPacket[31] = (uint8_t)((checksum >> 8) & 0xFF);
	}
