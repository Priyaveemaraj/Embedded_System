/*
 * sbus.c
 *
 *  Created on: 14-Jul-2026
 *      Author: priya
 */
#include "sbus.h"
uint8_t sbuspacket[25];
void updateSbusPacket(uint16_t *channel, uint8_t num_of_channels)
{
	sbusPacket[0]= 0X0F;
	sbusPacket[24]= 0X00;
	uint32_t bucket = 0;
	uint8_t bitInBucket = 0;
	uint8_t byteIndex = 1;

	for (int i = 0; i<num_of_channels; i++ )
	{
		bucket |= ((uint32_t)(channel[i] & 0X07FF))<<bitInBucket;
		bitInBucket = bitInBucket + 11;
		while(bitInBucket>=8)
		{
			sbusPacket[byteIndex++]=(uint8_t)(bucket & 0XFF);
			bucket>>=8;
			bitInBucket -=8;
		}
	}
	sbusPacket[23]=0X00;

}


