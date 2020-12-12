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
 * @file data.h 
 * @brief include declarations and documentation for the functions
 *
 * Each declaration provides comments with a description of the function,   	* the inputs, and return value. 
 *
 * @author Andrea Alvarez
 * @date 12/12/2020
 *
 */
 
 /**
 * @brief Convert Integer-to-ASCII 
 *
 * Needs to convert data from a standard integer type into an 
 * ASCII string.
 *
 * @param ptr Pointer to source
 * @param data Source
 * @param base Can support from 2 to 16
 *
 * @return ASCII string
 */
  uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
  
   /**
 * @brief Convert ASCII-to-Integer 
 *
 * Needs to convert data back from an ASCII represented string into an 
 * integer type.
 *
 * @param ptr Pointer to source
 * @param digits The number of digits 
 * @param base Can support from 2 to 16
 *
 * @return Integer
 */
  
  int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
