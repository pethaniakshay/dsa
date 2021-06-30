/*
 * documentation section:
 * main.cpp
 *
 *  Created on: 20-Feb-2020
 *      Author: sunbeam
 */

/* file inclusion section */
#include<cstdio>
#include"array_functions.h"
/* global declaration section */

/* entry point function */
int main(void)
{
	//int arr[SIZE] = {10,20,30,40,50,60,70,80,90,100};
	//int arr[SIZE] = {20,40,60,30,10,50};
	//int arr[SIZE] = {10,20,30,40,50,60};
	int arr[SIZE] = {20,40,60,80,50,10,70,30};

	//int key;


	//accept_array_elements(arr);
	display_array_elements(arr);

	//selection_sort(arr);
	//bubble_sort(arr);
	insertion_sort(arr);

	display_array_elements(arr);

	/*
	printf("enter the key: ");
	scanf("%d", &key);
	*/

	/*
	if( rec_linear_search(arr,0,key) )
		printf("%d is found in an array !!!\n", key);
	else
		printf("%d is not found in an array !!!\n", key);

	*/

	//bool result = linear_search(arr, key);
	//bool result = updated_linear_search(arr, key);
	/*
	bool result = binary_search(arr, key);

	if( result == true )
	{
		printf("no. of comparisons are: %d\n", comparisons);
		printf("%d is found in an array !!!\n", key);
	}
	else
	{
		printf("no. of comparisons are: %d\n", comparisons);
		printf("%d is not found in an array !!!\n", key);
	}
	*/

	return 0;
}

/* global declaration section */




