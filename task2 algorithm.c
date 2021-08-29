#include <stdio.h>
#include <time.h>

// function two swap two elements in array
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

//algorithm of insertion sort
void insertionSort(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) { 
        key = arr[i];
        j = i - 1;
       // Move elements which greater than key, position up
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
  
//algorithm of quickSort sort
//part1 
int partition (int arr[], int start, int n) 
{ 
    int pivot = arr[n]; // takes last element as pivot
    int i = (start - 1); // Index of smaller element and indicates the right position of pivot found so far
    int j;
   // places all smaller to left of pivot and all greater elements to right of pivot 
    for (j = start; j <= n - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[n]); 
    return (i + 1); 
} 
//part2
//The main function that implements QuickSort 
void quickSort(int arr[], int start, int n) 
{ 
    if (start < n) 
    { 
        int pi = partition(arr, start, n); 
        quickSort(arr, start, pi - 1); 
        quickSort(arr, pi + 1,n); 
    } 
} 

int main()
{
    int n=100000;
	int arr[100000];
	int arr2[100000];
	int i;
       for (i = 0; i < n; i++) {
            arr[i] = rand();
            arr2[i]= arr[i];
			}
    printf("Array of %d random numbers is intialized \n",n);
            
    clock_t Time_insertion , Time_Quick ;
       
    Time_Quick = clock();
    quickSort(arr, 0, n-1);
    Time_Quick = clock() - Time_Quick;
    double time_taken2 = ((double)Time_Quick)/CLOCKS_PER_SEC; // in seconds
    printf("\nThe array sorted using Quick sort in %f seconds \n", time_taken2);
   /*for (i = 0; i < n; i++) {
             printf(" %d \n",arr[i]);
			}
    		*/
    Time_insertion = clock();
    insertionSort(arr2, n);
    Time_insertion = clock() - Time_insertion;
    double time_taken = ((double)Time_insertion)/CLOCKS_PER_SEC; // in seconds
    printf("\nThe array sorted using insertion sort in  %f seconds \n", time_taken);
   /* for (i = 0; i < n; i++) {
             printf(" %d \n",arr2[i]);
	 	}*/
    return 0;
}
 



