// C++ Program for counting sort 
#include <bits/stdc++.h> 
#include <string.h> 
using namespace std; 
#define RANGE 255 

// This is the main function that sort  the given string arr[] in  alphabatical order 
void countSort(char arr[]) 
{ 
	// The output character array ehich will contain the sorted array 
	char output[strlen(arr)]; 

	// Creating a count array to store count
	// initialising the count array 0 
	int count[RANGE + 1], i; 
	memset(count, 0, sizeof(count)); 

	// Storing the count for each character 
	for (i = 0; arr[i]; ++i) 
		++count[arr[i]]; 

	// Change count[i] so that count[i] now contains actual position of this character in output array 
	for (i = 1; i <= RANGE; ++i) 
		count[i] += count[i - 1]; 

	// Output character array 
	for (i = 0; arr[i]; ++i) { 
		output[count[arr[i]] - 1] = arr[i]; 
		--count[arr[i]]; 
	} 

	// Copy the output array to arr, so that arr now contains sorted charactor
	for (i = 0; arr[i]; ++i) 
		arr[i] = output[i]; 
} 

// Main Driving Code
int main() 
{ 
	char arr[] = "defgcbjsnauy"; 

	countSort(arr); 

	cout << "Sorted character array is " <<endl<<arr; 
	return 0; 
} 
