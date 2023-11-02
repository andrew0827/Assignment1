#include "console.h"
#include "Tick_core.h"
#include <stdio.h>

#define S3  PORTDbits.RD6
#define S6  PORTDbits.RD7


#define TICK_SECOND 40000000
#define TIMEOUT     TICK_SECOND/5

static int32_t lastTick;

void Task1_init(void){
    printf("Starting\n");
    lastTick=TickGet();
}

void task1(void) {
    static int cnt = 0;
 	static enum {SM0 = 0, SM1, SM2} state = 0;
   	switch(state){
		case SM0:
            if (S3 == 0){
                printf("SM1\n");
                lastTick=TickGet();
                state = SM1;
			}
            else state = SM0;
			break;
            
		case SM1:
            if (tick_diff(lastTick)> TIMEOUT) {
                lastTick=TickGet();
                printf("SM2\n");
                state = SM2;

            }
            else state = SM1;
			break;
            
        case SM2:
            if (tick_diff(lastTick)> TIMEOUT/2) {
                lastTick=TickGet();
                printf("toggling\n");
            }
            if (S6 == 0){
                printf("SM0\n");
                state = SM0;
            }
            
            
            
            else state = SM2;
            break;
            
	}
}
