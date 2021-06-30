/*
 * main.cpp
 *
 *  Created on: 19-Feb-2020
 *      Author: sunbeam
 */
#include<cstdio>
#include"array_functions.h"


int main(void)
{
	int arr[SIZE] = {10,20,30,40,50,60,70,80,90,100};

	//accept_array_elements(arr);
	display_array_elements(arr);
	printf("sum of array ele's is: %d\n", array_sum(arr));
	printf("sum of array ele's is: %d\n", rec_array_sum(arr,0));



	return 0;
}




