/*
 * array_functions.cpp
 *
 *  Created on: 20-Feb-2020
 *      Author: sunbeam
 */
#include<cstdio>
#include"array_functions.h"

#define SWAP(a,b) {int t = a; a = b; b = t; }

int comparisons=0;

/* definitions of user defined functions */
void accept_array_elements(int arr[])
{
	int index;
	printf("enter array elements: \n");
	for( index =  0 ; index < SIZE ; index++ )
	{
		printf("enter arr[ %d ]: ", index);
		scanf("%d", &arr[index]);
	}
}

void display_array_elements(int arr[])
{
	int index;
	printf("array ele's are: ");
	for( index = 0 ; index < SIZE ; index++ )
	{
		printf("%4d", arr[index]);
	}
	printf("\n");
}

bool linear_search(int arr[], int key)
{
	int index;
	comparisons=0;

	for( index = 0 ; index < SIZE ; index++ )
	{
		comparisons++;
		if( arr[index] == key )
			return true;
	}

	return false;
}

bool rec_linear_search(int arr[],int index,int key)
{
	if( index == SIZE )
		return false;

	if( arr[index] == key )
		return true;

	return rec_linear_search(arr,index+1,key);
}

bool updated_linear_search(int arr[], int key)
{
	int index;
	comparisons=0;

	for( index = 0 ; index < SIZE && key >= arr[index]; index++ )
	{
		comparisons++;
		if( arr[index] == key )
			return true;
	}

	return false;

}


bool binary_search(int arr[], int key)
{
	int left = 0;
	int right = SIZE-1;
	comparisons=0;

	while( left <= right )
	{
		int mid = (left+right)/2;

		comparisons++;
		if( arr[mid] == key )
			return true;

		if( key < arr[mid] )
			right = mid-1;
		else
			left = mid+1;
	}

	return false;
}

void selection_sort(int arr[])
{
	int iterations=0;
	int comparisons=0;

	for( int sel_pos = 0 ; sel_pos < SIZE-1 ; sel_pos++ )
	{
		iterations++;
		for( int pos = sel_pos+1 ; pos < SIZE ; pos++ )
		{
			comparisons++;
			if( arr[ sel_pos ] > arr[ pos ] )
				SWAP(arr[sel_pos], arr[pos] );
		}
	}

	printf("no. of iterations are: %d\n", iterations);
	printf("no. of comparisons are: %d\n", comparisons);

}

void bubble_sort(int arr[])
{
	int it;
	int comparisons=0;
	bool flag = true;

	for( it = 0 ; it < SIZE-1 && flag == true ; it++ )
	{
		flag=false;
		for( int pos = 0 ; pos < SIZE-it-1 ; pos++ )
		{
			comparisons++;
			if( arr[ pos ] > arr[ pos+1 ] )
			{
				SWAP(arr[pos], arr[pos+1] );
				flag = true;
			}
		}
	}

	printf("no. of iterations are: %d\n", it);
	printf("no. of comparisons are: %d\n", comparisons);
}

/*
void bubble_sort(int arr[])
{
	int it;
	int comparisons=0;

	for( it = 0 ; it < SIZE-1 ; it++ )
	{
		for( int pos = 0 ; pos < SIZE-it-1 ; pos++ )
		{
			comparisons++;
			if( arr[ pos ] > arr[ pos+1 ] )
				SWAP(arr[pos], arr[pos+1] );
		}
	}

	printf("no. of iterations are: %d\n", it);
	printf("no. of comparisons are: %d\n", comparisons);
}
*/

void insertion_sort(int arr[])
{
	int pass=0;
	int while_cnt=0;

	for ( int i = 1 ; i < SIZE ; i++ )
	{
		pass++;
		int j = i-1;
		int key = arr[i];

		while( j >= 0 && key < arr[j] )
		{
			while_cnt++;
			//shift ele towards its right by 1 pos
			arr[j+1] = arr[j];
			j--;
		}

		//insert key at its appropriate position
		arr[j+1] = key;
	}

	printf("no. of passes/iterations: %d\n", pass);
	printf("while_cnt: %d\n", while_cnt);
}












