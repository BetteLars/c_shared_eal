/*
 * readkeys.c
 *
 *  Created on: 08/02/2012
 *      Author: Lasse
 */
/*
 ============================================================================
 Name        : ReadKey_program.c
 Author      : Lars
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "readkeys.h"

int Readkeys(int RawKeys)
{

	static int key_count[MAXBIT-1] = { 0,0,0,0,0,0,0,0 };

	int loop_counter;

		for( loop_counter = 0; loop_counter < MAXBIT; loop_counter++)
			{
				if( RawKeys & (1 << loop_counter) )
					{
						key_count[loop_counter] = key_count[loop_counter] + 1;
					}
				else
					{
						key_count[loop_counter] = 0;
					}
			}

		for( loop_counter = 0; loop_counter < MAXBIT; loop_counter++)
			{
				if( key_count[loop_counter] > 5 )
					{
						key_count[loop_counter] = 0;
						return loop_counter;
					}
			}


//	if (RawKeys == 1 <<KEY0BIT)
//		{
//		if(RawKeys == 5 << key0_count)
//			{
//				key0_count = 0;
//			return KEY0_EVENT;
//			}
//
//			key0_count++;
//		}
//
//	if (RawKeys == 1 <<KEY1BIT)
//			{
//			if(RawKeys == 5 << key1_count)
//				{
//					key1_count = 0;
//				return KEY1_EVENT;
//				}
//
//				key1_count++;
//			}

	return NO_EVENT;
}
