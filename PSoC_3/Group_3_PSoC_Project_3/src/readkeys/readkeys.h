/*
 * readkeys.h
 *
 *  Created on: Feb 10, 2012
 *      Author: Lasse
 */

#ifndef READKEYS_H_
#define READKEYS_H_
// Keys definitions
	enum bitNumbers { KEY0BIT, KEY1BIT, KEY2BIT, KEY3BIT, KEY4BIT, KEY5BIT, KEY6BIT, KEY7BIT, MAXBIT};
// Event definitions
	enum events 	{ KEY0_EVENT_Enter, KEY1_EVENT_Cancel, KEY2_EVENT_Left, KEY3_EVENT_Rigth, KEY4_EVENT, KEY5_EVENT, KEY6_EVENT, KEY7_EVENT, TICK, NO_EVENT, MAXEVENTS };
// State definitions
	enum states		{ MENU, FALLOUTTIMER, KILLSWITCH, DB_lEVEL_setting, RESET_DEF,SoundMesure,MAXSTATES };

#endif /* READKEYS_H_ */
