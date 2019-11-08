#ifndef SortingComparison_hpp
#define SortingComparison_hpp


#include <iostream>

//describes the data distribution in the array values_
enum data_distribution { RANDOM, INCREASING, DECREASING };


class SortingComparison
{
public:

   //parameterized constructor allocate values_ with array_size
   SortingComparison(size_t array_size);


   /*****************************************************************/
   /********************* SORTING FUNCTIONS *************************/
   /*****************************************************************/

   /**
   @post Sorts an array in ascending order using the selection sort algorithm.
   @return the number of comparisons made by the algorithm
   */
   int selectionSort(int a[], size_t size);

   /**
   @post Sorts an array in ascending order using insertion sort.
   @param a the array to sort
   @param size of the array
   @return the number of comparisons made by the algorithm
   */
   int insertionSort(int a[], size_t size);

   /**
   @post Sorts an array in ascending order using merge sort.
   @param a the array to be sorted
   @param from the first position in the range to sort
   @param to the last position in the range to sort (included)
   @return the number of comparisons made by the algorithm
   */
   int mergeSort(int a[], int from, int to);


   /**
   @post Sorts an array in ascending order using quick sort.
   @param a the array to be sorted
   @param from the first position in the range to sort
   @param to the last position in the range to sort (included)
   @return the number of comparisons made by the algorithm
   */
   int quickSort(int a[], int from, int to);

   /*****************************************************************/
   /****************** TEST FUNCTIONS *******************************/
   /*****************************************************************/


   //************* DEFINE runComparison HERE!!!! ***********************//
  void runComparison(data_distribution array_type);
private:

   const size_t SIZE; // the size of values_
   int* values_; //an array of integer values to be sorted


               /*****************************************************************/
               /********************* SORTING HELPERS *************************/
               /*****************************************************************/

               /**
               helper for selectionSort
               @post Gets the position of the smallest element in an array range.
               @param a the array
               @param from the beginning of the range
               @param to the end of the range
               @return the position of the smallest element in
               the range a[from]...a[to]
               */
   int minPosition(int a[], int from, int to);

   /**
   helper for mergeSort
   @post Merges two adjacent subarrays.
   @param a the array with the elements to merge
   @param from the start of the first subarray
   @param mid the end of the first subarray
   @param to the end of the second subarray
   */
   void merge(int a[], int from, int mid, int to);


   /**
   helper for quickSort
   Partitions a portion of an array.
   @param a the array to partition
   @param from the first index of the portion to be partitioned
   @param to the last index of the portion to be partitioned
   @return the last index of the first partition
   */
   int partition(int a[], int from, int to);


};//end SortingComparison

#endif /* SortingComparison_hpp */
