#include "SortingComparison.hpp"

//include for random functions

#include <stdlib.h>

#include <time.h>

using namespace std;

//global varible for counting comparsion of all sorting algorithm

int countSelection=0;

int countInsertion=0;

int countMerge=0;

int countQuick=0;

//parameterized constructor allocate values_ with array_size

SortingComparison::SortingComparison(size_t array_size) :

SIZE(array_size), values_(new int[SIZE])

{

}

/*****************************************************************/

/********************* SORTING FUNCTIONS *************************/

/*****************************************************************/

/*************** SELECTION SORT + HELPER **************************/

/**

@post Gets the position of the smallest element in an array range.

@param a the array

@param from the beginning of the range

@param to the end of the range

@return the position of the smallest element in

the range a[from]...a[to]

*/

int SortingComparison::minPosition(int a[], int from, int to)

{

int min_pos = from;

for (int i = from + 1; i <= to; i++)

if (a[i] < a[min_pos])

{ min_pos = i;

countSelection++;

};

return min_pos;

}



/**

@post Sorts an array in ascending order using the selection sort algorithm.

@return the number of comparisons made by the algorithm

*/

int SortingComparison::selectionSort(int a[], size_t size)

{

for (int i = 0; i < size; i++)

{

// Find the position of the minimum

int min_pos = minPosition(a, i, static_cast<int>(size - 1));

// Swap the next element and the minimum

std::swap(a[i], a[min_pos]);

}

return countSelection; //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS

}



/*************** INSERTION SORT **************************/



/**

@post Sorts an array in ascending order using insertion sort.

@param a the array to sort

@param size of the array

@return the number of comparisons of two array elements made by the algorithm

*/

int SortingComparison::insertionSort(int a[], size_t size)

{ int count=0;

for (int i = 1; i < size; i++)

{

int next = a[i];

// Move all larger elements up

int j = i;

while (j > 0 && a[j - 1] > next)

{ countInsertion++;

a[j] = a[j - 1];

j--;

}

// Insert the element

a[j] = next;

count = countSelection;

}

return count; //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS

}



/************************* MERGE SORT + HELPER **************************/

/**

@post Merges two adjacent subarrays.

@param a the array with the elements to merge

@param from the start of the first subarray

@param mid the end of the first subarray

@param to the end of the second subarray

*/

void SortingComparison::merge(int a[], int from, int mid, int to)

{

int n = to - from + 1; // Size of the range to be merged

// Merge both halves into a temporary array temp_array

int* temp_array = new int[n];

int i1 = from;

// Next element to consider in the first half

int i2 = mid + 1;

// Next element to consider in the second half

int j = 0; // Next open position in temp_array

// Compare elements in subarrays for merging

// As long as neither i1 nor i2 is past the end,

// move the smaller element into temp_array

while (i1 <= mid && i2 <= to)

{

if (a[i1] < a[i2])

{ countMerge++;

temp_array[j] = a[i1];

i1++;

}

else

{ countMerge++;

temp_array[j] = a[i2];

i2++;

}

j++;

}



// Note that only one of the two while loops below is executed

// Copy any remaining entries of the first half

while (i1 <= mid)

{ countMerge++;

temp_array[j] = a[i1];

i1++;

j++;

}

// Copy any remaining entries of the second half

while (i2 <= to)

{ countMerge++;

temp_array[j] = a[i2];

i2++;

j++;

}

// Copy back from the temporary array

for (j = 0; j < n; j++)

{

a[from + j] = temp_array[j];

}

delete[] temp_array;

}

/**

@post Sorts the elements in a range of a array.

@param a the array with the elements to sort

@param from the first position in the range to sort

@param to the last position in the range to sort (included)

@return the number of comparisons made by the algorithm

*/

int SortingComparison::mergeSort(int a[], int from, int to)

{

if (from == to) { return 0; }

int mid = (from + to) / 2;

// Recursively sort the first and the second half

mergeSort(a, from, mid);

mergeSort(a, mid + 1, to);

merge(a, from, mid, to);

return countMerge; //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS

}



/************************* QUICK SORT + HELPER**************************/

/**

Partitions a portion of an array.

@param a the array to partition

@param from the first index of the portion to be partitioned

@param to the last index of the portion to be partitioned

@return the last index of the first partition

*/

int SortingComparison::partition(int a[], int from, int to)

{

int pivot = a[from];

int i = from - 1; //index of data item being compared from left

int j = to + 1; //index of data item being compared from right

while (i < j) // as long as i and j did not cross (meet)

{

i++;

while (a[i] < pivot)//increment i until a[i] >= pivot

{ i++;

countQuick++;

}

j--;

while (a[j] > pivot) //decrement j until a[j] <= pivot

{ j--;

countQuick++;

}

if (i < j)

std::swap(a[i], a[j]);

}

return j; // the pivot index

}

/**

@post Sorts an array in ascending order using quick sort.

@param a the array to sort

@param from the first index of the portion to be sorted

@param to the last index of the portion to be sorted

@return the number of comparisons made by the algorithm

*/

int SortingComparison::quickSort(int a[], int from, int to)

{

if (from >= to) { return 0; }

int p = partition(a, from, to);

quickSort(a, from, p);

quickSort(a, p + 1, to);

return countQuick; //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS

}

/*****************************************************************/

/****************** TEST FUNCTION *******************************/

/*****************************************************************/

//************* IMPLEMENT runComparison HERE!!!! ************//

/**

@post Sort a copy of value_ in ascending order with each available sorting functions

@param array_type data_distribution of value_ in (random increasing decreasing)

*/

void runComparsion(data_distribution array_type){

//calling the class Sorting Comparsions and make object s with size 5

int n=10;

SortingComparison s(10);

//assume a array of length 5

int a[]={11,33,22,55,44,5,4,6,3,8};

if(array_type==RANDOM) {

// an array for making copy of array in random manner

int b[5];

//setting seend in random functions

srand ( time(NULL) );

//making an copy array a in b with random function

for(int i=0;i<5;i++){

int randomElement = rand() % 4; //generates a random number between 0 and 3

b[i]= a[randomElement];

}

//now making sorting of copied array

cout<<"Selection Sort Comparsions : "<<s.selectionSort(b,n)<<endl;

cout<<"Insertion Sort Comparsions : "<<s.insertionSort(b,n)<<endl;

cout<<"Merge Sort Comparsions : "<<s.mergeSort(b,0,n-1)<<endl;

cout<<"Quick Sort Comparsions : "<<s.quickSort(b,0,n-1)<<endl;

}

else if(array_type == INCREASING){

//making an copy array a in b with INCREASING function

int b[5];

for(int i=0;i<5;i++){

b[i]=a[i];

}

//sorting - INCREASING ORDER

int temp=0;

for(int i=0;i<5;i++)

{   

for(int j=i+1;j<n;j++)

{

if(b[i]>b[j])

{

temp =b[i];

b[i]=b[j];

b[j]=temp;

}

}

}

//now making sorting of copied array

cout<<"Selection Sort Comparsions : "<<s.selectionSort(b,n)<<endl;

cout<<"Insertion Sort Comparsions : "<<s.insertionSort(b,n)<<endl;

cout<<"Merge Sort Comparsions : "<<s.mergeSort(b,0,n-1)<<endl;

cout<<"Quick Sort Comparsions : "<<s.quickSort(b,0,n-1)<<endl;

}

else if (array_type == DECREASING){

//making an copy array a in b with DECREASING function

int b[5];

for(int i=0;i<5;i++){

b[i]=a[i];

}

//sorting - DECREASING ORDER

int temp=0;

for(int i=0;i<5;i++)

{   

for(int j=i+1;j<n;j++)

{

if(b[i]<b[j])

{

temp =b[i];

b[i]=b[j];

b[j]=temp;

}

}

}

//now making sorting of copied array

cout<<"Selection Sort Comparsions : "<<s.selectionSort(b,n)<<endl;

cout<<"Insertion Sort Comparsions : "<<s.insertionSort(b,n)<<endl;

cout<<"Merge Sort Comparsions : "<<s.mergeSort(b,0,n-1)<<endl;

cout<<"Quick Sort Comparsions : "<<s.quickSort(b,0,n-1)<<endl;

}

else{

cout<<"Invalid choice "<<endl;

}

}

int main(){

cout<<"For RANDOM element in array"<<endl;

runComparsion(RANDOM);

cout<<"==========================\n"<<endl;

cout<<"For INCREASING element in array"<<endl;

runComparsion(INCREASING);

cout<<"==========================\n"<<endl;

cout<<"For DECREASING element in array"<<endl;

runComparsion(DECREASING);

cout<<"==========================\n"<<endl;

return 0;

}


