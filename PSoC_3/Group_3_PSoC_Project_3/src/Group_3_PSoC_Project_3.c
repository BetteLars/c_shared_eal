/*
 ============================================================================
 Name        : Group_3_PSoC_Project_3.c
 Author      : Lars, Ibrahim, Lukas
 Version     :
 Copyright   : Your copyright notice
 Description : PSoC 4 butten interface, Project 3, Ansi-style
 ============================================================================
 */
// Keys definitions
//	enum bitNumbers { KEY0BIT, KEY1BIT, KEY2BIT, KEY3BIT, KEY4BIT, KEY5BIT, KEY6BIT, KEY7BIT, MAXBIT};
// Event definitions
//	enum events 	{ KEY0_EVENT_Enter, KEY1_EVENT_Cancel, KEY2_EVENT_Left, KEY3_EVENT_Rigth, KEY4_EVENT, KEY5_EVENT, KEY6_EVENT, KEY7_EVENT, TICK, NO_EVENT, MAXEVENTS };
// State definitions
// 	enum states		{ MENU, FALLOUTTIMER, KILLSWITCH, DB_lEVEL_setting, RESET_DEF, SoundMesure, MAXSTATES };

#include <stdio.h>
#include <stdlib.h>

#include "readkeys/readkeys.h"

int TS_State = SoundMesure;

// forward function declarations
void Do( int State );
void OnEnter( int State );
void OnExit( int State );

void testReadKeys( void );
void DisplayMenu( int event );
//------------------------------


int main( void )
	{

		puts( "Testing the readkeys function ..." ); /* prints Testing the Readkeys function */
		testReadKeys();
		DisplayMenu(KEY0_EVENT_Enter);
		return EXIT_SUCCESS;
	}

void testReadKeys( void )
	{
		// Testing key0 only
		if( Readkeys( 0x01 ) != NO_EVENT )
			{ printf( " failed on 1. call" );}
		else if( Readkeys( 0x01 ) != NO_EVENT )
			{ printf( " failed on 2. call" );}
		else if( Readkeys( 0x01 ) != NO_EVENT )
			{ printf( " failed on 3. call" );}
		else if( Readkeys( 0x01 ) != NO_EVENT )
			{ printf( " failed on 4. call" );}
		else if( Readkeys( 0x01 ) != NO_EVENT )
			{ printf( " failed on 5. call" );}
		else if( Readkeys( 0x01 ) != KEY0_EVENT_Enter )
			{ printf( " failed on 6. call" );}

		// test key1 only
		else if( Readkeys( 0x02 ) != NO_EVENT )
			{ printf( " failed on 7. call" );}
		else if( Readkeys( 0x02 ) != NO_EVENT )
			{ printf( " failed on 8. call" );}
		else if( Readkeys( 0x02 ) != NO_EVENT )
			{ printf( " failed on 9. call" );}
		else if( Readkeys( 0x02 ) != NO_EVENT )
			{ printf( " failed on 10. call" );}
		else if( Readkeys( 0x02 ) != NO_EVENT )
			{ printf( " failed on 11. call" );}
		else if( Readkeys( 0x02 ) != KEY1_EVENT_Cancel )
			{ printf( " failed on 12. call" );}

		// let go of keys
		else if( Readkeys( 0x00 ) != NO_EVENT )
			{ printf( " failed on 13. call" );}

		// test key0 and key1 at the same time
		else if( Readkeys( 0x18 ) != NO_EVENT )
			{ printf( " failed on 14. call" );}
		else if( Readkeys( 0x18 ) != NO_EVENT )
			{ printf( " failed on 15. call" );}
		else if( Readkeys( 0x18 ) != NO_EVENT )
			{ printf( " failed on 16. call" );}
		else if( Readkeys( 0x18 ) != NO_EVENT )
			{ printf( " failed on 17. call" );}
		else if( Readkeys( 0x18 ) != NO_EVENT )
			{ printf( " failed on 18. call" );}
		else if( Readkeys( 0x18 ) != KEY3_EVENT_Rigth )
			{ printf( " failed on 19. call" );}
		else if( Readkeys( 0x18 ) != KEY4_EVENT )
			{ printf( " failed on 20. call" );}
		else if( Readkeys( 0x18 ) != NO_EVENT )
			{ printf( " failed on 21. call" );}
		else if( Readkeys( 0x18 ) != NO_EVENT )
			{ printf( " failed on 22. call" );}
		else
			  printf( "passed !" );
	}
void DisplayMenu(int event)
	{
	int NextState = TS_State;
 	switch( TS_State )
		{
		case SoundMesure:
				switch (event )
				{
				case KEY0_EVENT_Enter:
					NextState = MENU;
					printf("Going to Menu \n");
					break;
				default:
					break;
				}
				break;
		case MENU:

			switch (event )
			{
			case KEY2_EVENT_Left:

				break;

			case KEY3_EVENT_Rigth:

				break;

			case KEY1_EVENT_Cancel:
				NextState = SoundMesure;
				break;

			case KEY0_EVENT_Enter:

				break;

			case TICK:

				break;
			default:
				break;
			}
			break;

		default:
			break;
				// The program should never get here !
		}
		if (NextState != TS_State)
		{
			OnExit(TS_State);
			OnEnter(NextState);
			TS_State = NextState;
		}

		Do( TS_State );
	}


void OnEnter( int State )
	{

	}

void OnExit( int State )
	{

	}

void Do( int State )
	{

	}
