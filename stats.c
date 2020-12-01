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
 * @file stats.c
 * @brief analyze of a array and report analytics
 *
 * Functions that can analyze an array of unsigned char data items and   
 * report analytics on the maximum, minimum, mean, and median of the data
 * set.
 *
 * @author Andrea Alvarez
 * @date 11/1/2020
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
   int NoElements = sizeof(test)/sizeof(test[0]);
   int MinValue, MaxValue;
   float MeValue, MedValue;
   
  /* Statistics and Printing Functions Go Here */  
  
  printf("\n Array before the sort \n");
  print_array(test);
  
  MedValue=find_median(sort_array(test,NoElements),NoElements);
  MeValue=find_mean(test,NoElements);
  MaxValue=find_maximun(test,NoElements);
  MinValue=find_minimun(test,NoElements);
  print_statistics(MinValue,MaxValue,MeValue,MedValue);
  

  printf("\n Array after the sort \n");
  sort_array(test,NoElements);
  print_array(test);
}

void print_statistics(int MinimunValue,int MaximunValue,float MeanValue,float MediamValue)
{
  	printf("\n The minimum of the array is %d", MinimunValue);
  	printf("\n The maximum of the array is %d", MaximunValue);
  	printf("\n The mean of the array is %0.2f", MeanValue);
  	printf("\n The mediam of the array is %0.2f \n", MediamValue);
} 
  
void print_array(unsigned char testArray[]) 
{
    printf("\n The values of the array are:");
  	for(int i=0; i<SIZE; i++)
  	{
  		printf("\n %d", testArray[i]);
  	}
}  

float find_median(unsigned char SortArray[],int NoElem) 
{
    float Mediam;
    int middle, next;
    middle=NoElem/2;
    next=middle-1;
  	if(NoElem%2==0)
  	{
  		Mediam=(SortArray[middle]+SortArray[next])/2;
  		return Mediam;
  		
  	}
  	else
  	{
		Mediam=SortArray[next];
		return Mediam;
  	}
}

float find_mean(unsigned char testArray[],int NoElem)
{
	float sum, Mean;
	
	for(int i=0; i<SIZE; i++)
	{
		sum= sum+testArray[i];
	}
	Mean=sum/NoElem;
	return Mean;	
}

int find_maximun(unsigned char testArray[], int NoElem)
{
	for(int i=0; i<NoElem; i++)
	{
		if(testArray[0]<testArray[i])
		{
			testArray[0]=testArray[i];
		}
	}
	return testArray[0];
}

int find_minimun(unsigned char testArray[], int NoElem)
{
	for(int i=0; i<NoElem; i++)
	{
		if(testArray[0]>testArray[i])
		{
			testArray[0]=testArray[i];
		}
	}
	return testArray[0];
}

unsigned char * sort_array(unsigned char testArray[], int NumElem) 
{
  int max;
  
  for(int i=0; i<NumElem; i++)
  {
  	for(int j=i+1; j<NumElem; j++)
  	{
  		if(testArray[i]<testArray[j])
  		{
  			max=testArray[i];
  			testArray[i]=testArray[j];
  			testArray[j]=max;
  		}
  	}
  }
  return testArray;
}
/* Add other Implementation File Code Here */
