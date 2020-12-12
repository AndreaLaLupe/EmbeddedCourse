/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file debug.c
 * @brief Debug printing
 *
 * Function that allow for debugging functionality by printing data values
 * at specific memory location by terminal.
 
 * @author Andrea Alvarez
 * @date 12/12/2020
 *
 */
 
 #include <stdio.h>
 #include <stdint.h>
 #include "debug.h"
 
 void print_memory(uint8_t *beginning, uint32_t lenght){
 
 //Loop for print values
 
 	for(int i=0; i<length; i++){
 		#ifdef VERBOSE
 		printf("Address: %p | Hex Value: 0x%02x \n", beginning, *beginning);
 		#endif
 		beginning++;
 	}
 	#ifdef VERBOSE
 		printf("\n");
 	#endif
 }
