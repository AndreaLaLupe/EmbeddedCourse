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
 * @file data.c
 * @brief Data manipulation
 *
 * Functions that can manipulate some information and data, they  
 * are very simple.
 *
 * @author Andrea Alvarez
 * @date 12/12/2020
 *
 */
 
 #include <stdio.h>
 #include <stdint.h>
 #include <stdlib.h>
 #include <math.h>
 #include "memory.h"
 #include "data.h"
 
 uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
 
 //Variables to store de mod and the lenght
 	int remainder;
 	int length=0;
 
 //Loop until de data equals 0
 	while(data!=0){
 		remainder=data%base;
 		data=data/base;
 		
 	//converts digits A-F to ASCII
 		if(remainder>9){
 			*ptr=(uint8_t)remainder+55;
 		}
 	//converts digits 0-9 to ASCII
 		else{
 			*ptr=remainder+48;
 		}
 		
 		ptr++;
 		length++;
 	}
 
 //restores to original value
 	ptr=ptr-length;
 	
 //Put in the correct order
 	my_reverse(ptr,length);
 	
 	return length;
 }
 
 int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
 
 	uint32_t j=0, number=0, mult=0;
 	int8_t i=0, dig=0;
 
 	for(i=digits-1;i>=0;i--){
 		dig=*(ptr+i);
 		
 		if(65<=dig && dig <=70){
 			dig=dig-55;
 		}
 		else{
 			dig=dig-48;
 		}
 		
 		mult=(int32_t)pow((double)base,(double)j);
 		number+=dig*mult;
 		
 		j++;
 	
 	}
 
 	return number;
 }
