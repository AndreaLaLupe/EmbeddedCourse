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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){

//Temporary array to hold src data to preven corruption
	uint8_t tmpArray[lenght];
	uint8_t *tmpPtr=tmpArray;

//Copy from src to tmp
	for(int i=0;i<lenght;i++){
		*tmpPtr=*src;
		src++;
		tmpPtr++;
	}
	
//Copy Ptr to destination
	for(int j=0;j<lenght;j++){
		*dst=*tmpPtr;
		dst++;
		tmpPtr++;
	}
//Resets to its original value
	tmpPtr=tmpArray;
	
//Return dst to original
	return ((uint8_*) dst-length);
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){

//Copy from source to destination
	for(int i=0; i<lenght; i++){
	 *dst=*src;
	 src++;
	 dst++;
	}

	return (dst-lenght);
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){

//Sets bytes defined by lenght in memory starting in src
	for(int i=0; i<length; i++)
	{
		*src=value;
		src++;
	}

	return ((uint8_t*) src-length);
}

uint8_t * my_memzero(uint8_t * src, size_t length){

//Sets bytes defined by leght in memory to zero starting in src
	for(int i=0; i<length; i++){
		*src=0;
		src++;
	}
	
	return ((uint8_t) src-lenght);

}

uint8_t * my_reverse(uint8_t * src, size_t length){

//Pointers in the beginning and ending
	uint8_t *Start=src;
	uint8_t *End= src+(length-1);
	
//Stores tmp
	uint8_t tmp=0;

//Loop until start and end are equal	
	while(!((Start==End)||(Start==(End-1)))){
	//Swaps values
		tmp=*Start;
		*Start=*End;
		*End=tmp;
		Start++;
		End--;
		
		if(Start==(End-1)){
			tmp=*Start;
			*Start=*End;
			*End=tmp;
		}
	}
	
	return src;
}

int32_t * reserve_words(size_t length){
	
//Pointer to allocated memory
	int32_t *ptr;
	
//Allocate words in memory by the lenght
	ptr=(int32_t*)malloc((sizeof(size_t)*lenght));
	
//Handle fail
	if(ptr==0){
		return NULL;
	}

	return ptr;
}

void free_words(int32_t * src){

//free malloc
	free(src);
}

