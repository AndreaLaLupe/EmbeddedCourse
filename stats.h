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
 * @file stats.h 
 * @brief include declarations and documentation for the functions
 *
 * Each declaration provides comments with a description of the function,   	* the inputs, and return value. 
 *
 * @author Andrea Alvarez
 * @date 11/1/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
* @brief print_statistics
* A function that prints the statistics of an array including minimum,  
* maximum, mean, and median.
* @param test Array with the numbers
*/
void print_statistics(int MinimunValue,int MaximunValue,float MeanValue,float MediamValue);


/**
* @brief print_array
* Given an array of data and a length, prints the array to the screen.
* @param test Array with the numbers
*/
void print_array(unsigned char testArray[]);

/**
* @brief find_median
* Given an array of data and a length, returns the median value.
* @param SortArray with the numbers in descending order
* @param NoElem size of the array
* @return Mediam with the result
*/
float find_median(unsigned char SortArray[],int NoElem); 

/**
* @brief find_mean
* Given an array of data and a length, returns the mean value.
* @param TestArray with the numbers of the array
* @param NoElem size of the array
* @return Mean with the result
*/
float find_mean(unsigned char testArray[],int NoElem);

/**
* @brief find_maximun
* Given an array of data and a length, returns the maximun value.
* @param TestArray with the numbers of the array
* @param NoElem size of the array
* @return Maximun with the result
*/
int find_maximun(unsigned char testArray[], int NoElem);

/**
* @brief find_minimun
* Given an array of data and a length, returns the minimun value.
* @param TestArray with the numbers of the array
* @param NoElem size of the array
* @return Maximun with the result
*/
int find_minimun(unsigned char testArray[], int NoElem);

/**
* @brief sort_array
* Given an array of data and a length, sorts the array from largest to    * smallest.
* @param TestArray with the numbers of the array
* @param NoElem size of the array
* @return SortArray with the result
*/
unsigned char * sort_array(unsigned char testArray[], int NumElem); 

#endif /* __STATS_H__ */
