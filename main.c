/******************************************************************************
 * 	FileName:     main.c
 *
 * This assignment must be completed in class.  
 * You don't need to hand over the source code but 
 * you have until the end of the class to complete it 
 * and give a demo to the teacher.
 *
 * November 2023
 * 		
 ******************************************************************************/

#include <stdio.h>
#include "initBoard.h"
#include "console.h"
#include "Tick_core.h"


int main( void){
    
    uart1_init();
    set_stdio(C_UART1);
    Task1_init();
    
    //Super loop
    while( 1){
		task1(); // Runs task1			
	}//while(1))

}// main

