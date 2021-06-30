/*
 * array_functions.h
 *
 *  Created on: 20-Feb-2020
 *      Author: sunbeam
 */

#ifndef ARRAY_FUNCTIONS_H_
#define ARRAY_FUNCTIONS_H_


#define SIZE 8

extern int comparisons;

/* declarations of user defined functions */
void accept_array_elements(int arr[]);
void display_array_elements(int arr[]);
bool linear_search(int arr[], int key);
bool rec_linear_search(int arr[],int index,int key);
bool updated_linear_search(int arr[], int key);
bool binary_search(int arr[], int key);
void selection_sort(int arr[]);//pointer to 1-d array
//void selection_sort(int *arr);//pointer to addr of first ele
void bubble_sort(int arr[]);
void insertion_sort(int arr[]);

#endif /* ARRAY_FUNCTIONS_H_ */
