#include "console.h"
#include "Tick_core.h"
#include <stdio.h>

#define S3  PORTDbits.RD6


#define TICK_SECOND 40000000
#define TIMEOUT     TICK_SECOND/20

static int32_t lastTick;

void Task1_init(void){
    printf("Starting\n");
    lastTick=TickGet();
}

void task1(void) {
    static int cnt = 0;
 	static enum {SM0 = 0, SM1} state = 0;
   	switch(state){
		case SM0:
            if(tick_diff(lastTick)> TIMEOUT){
                printf("toggling %d\n", cnt++);
                lastTick=TickGet();
                state = SM1;
			}
            else state = SM0;
			break;
		case SM1:
            state = SM0;
			break;            
	}
}
