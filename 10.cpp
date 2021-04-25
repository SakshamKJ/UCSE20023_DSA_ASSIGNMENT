#include <iostream> 
using namespace std; 


void heapify(int arr[], int n, int i) 
{ 
	int largest = i; 
	int left = 2*i + 1; 
	int right = 2*i + 2;
	if (left < n && arr[left] > arr[largest]) 
		largest = left; 

	if (right < n && arr[right] > arr[largest]) 
		largest = right; 

	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 
		heapify(arr, n, largest); 
	} 
} 

void buildheap(int arr[],int n){
    for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i);
}
void heapSort(int arr[], int n) 
{  
	buildheap(arr,n); 

	for (int i=n-1; i>0; i--) 
	{ 
		swap(arr[0], arr[i]);
		heapify(arr, i, 0); 
	} 
} 

void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; ++i) 
		cout << arr[i] << " "; 
} 
 
int main() 
{ 
	int arr[] = {12,18,23,01,5,8,123,98,49,43,20,56,77}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	heapSort(arr, n); 

	cout << "Sorted array is: "; 
	printArray(arr, n); 
} 

