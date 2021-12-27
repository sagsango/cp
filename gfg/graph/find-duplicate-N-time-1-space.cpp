/*

https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/

Find duplicates in O(n) time and O(1) extra space | Set 1


Traverse the array from start to end.
For every element,take its absolute value and if the abs(array[i])‘th element is positive, the element has not encountered before, else if negative the element has been encountered before print the absolute value of the current element.
 */


// C++ code to find
// duplicates in O(n) time
#include <bits/stdc++.h>
using namespace std;

// Function to print duplicates
void printRepeating(int arr[], int size)
{
	int i;
	cout << "The repeating elements are:" << endl;
	for (i = 0; i < size; i++) {
		if (arr[abs(arr[i])] >= 0)
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		else
			cout << abs(arr[i]) << " ";
	}
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 1, 3, 6, 6 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printRepeating(arr, arr_size);
	return 0;
}

// This code is contributed
// by Akanksha Rai


