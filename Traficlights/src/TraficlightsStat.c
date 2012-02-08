/*
 ============================================================================
 Name        : Traficlights.c
 Author      : Lars
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/
 /*
 * Example code for a very simple statemachine.
 *
 * Used in teaching C programming on embedded systems at EAL
 *
 */

#include <stdio.h>
#include <stdlib.h>

// State definitions
enum states { RED, RED_YELLOW, GREEN, YELLOW, MAXSTATES };
// Event definitions
enum events { QUEUE, TICK, MAXEVENTS };

int V_Substat = RED;
int H_Substat = RED;

// forward function declarations
void Do_Main();
void Do( int State );
void OnEnter( int State);
void OnExit( int State);
int TurnstileSM(int event, int TS_State);
//------------------------------

int main()
{	// By sending hardcoded events to the SM, it is possible to
	// simulate how it works.
    int i;

    for(i=0; i<8; i++)
			{
		V_Substat=		TurnstileSM( TICK, V_Substat );
			}
    /* In an actual system it would look more like this:
     *
     * while (1)
     * {
     * 		event = Input();
     * 		TurnstileSM( event );
     * }
     *
     */
    return 0;
}

void Do_Main()
{

}


/* The SM does not know anything about the system. This way it can be tested on a
 * different C compiler very easily.
 */
int TurnstileSM( int event, int TS_State )
{
    int NextState = TS_State;
    switch( TS_State )
    {
		case RED:
			switch ( event )
			{
			case TICK:
				NextState = RED_YELLOW;
				break;
			default:
				break;
			}
			break;

		case RED_YELLOW:
			switch ( event )
			{
			case TICK:
				NextState = GREEN;
				break;

			default:
				break;
			}
			break;

		case GREEN:
			switch ( event )
			{
			case TICK:
				NextState = YELLOW;
				break;

			default:
				break;
			}
			break;

		case YELLOW:
			switch ( event )
			{
			case TICK:
				NextState = RED;
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
    	return TS_State;
}

/* The 3 functions OnEnter, OnExit and Do are were all the fun happens.
 * Theee functions are written specifically for this system, and must be replaced
 * if the SM is used somewhere else - say on an embedded system.
 *
 * For simulating the SM a bunch of printf statements should be put here.
 */

void OnEnter( int State )
{

}

void OnExit( int State)
{

}

void Do( int State)
{
    switch (State)
    {
        case RED:
            printf("RED\n");
            break;
        case RED_YELLOW:
            printf("RED_YELLOW\n");
            break;
        case GREEN:
            printf("GREN\n");
            break;
        case YELLOW:
			printf("YELLOW\n");
			break;
    }
}

