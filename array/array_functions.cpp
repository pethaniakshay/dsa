/*
 * array_functions.cpp
 *
 *  Created on: 19-Feb-2020
 *      Author: sunbeam
 */

#include<cstdio>
#include"array_functions.h"

void accept_array_elements(int arr[])
{
	printf("enter array elements:\n");
	for( int index = 0 ; index < SIZE ; index++ )
	{
		printf("enter arr[ %d ] : ", index);
		scanf("%d", &arr[index]);
	}
}

void display_array_elements(int arr[])
{
	printf("array ele's are: ");
	for( int index = 0 ; index < SIZE ; index++ )
		printf("%4d", arr[index]);
	printf("\n");
}

int array_sum(int arr[])
{
	int sum = 0;

	for( int index = 0 ; index < SIZE ; ++index )
	{
		sum += arr[index];
	}

	return sum;
}

int rec_array_sum(int arr[], int index)
{
	if( index == SIZE )
		return 0;

	return ( arr[index] + rec_array_sum(arr,index+1));
}







