#include<iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
using namespace std;

void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

void fillarr(int *arr, int n){
    for (int i = 0; i < n; i++){
        arr[i] = rand();
    }
    return;
}

int main() {
   int n;
   chrono::time_point<chrono::steady_clock> start, end1; // create two time_point objects start and end1.
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   //cout << "Enter elements:" << endl;
   //for(int i = 0; i<n; i++) {
   //   cin >> arr[i];
   //}

   int Decision;
   cout << "Would you like to see Runtime for: " << endl << "     1: Pre-Sorted " << endl << "     2: Reverse Sorted" << "     3: Half-Sorted " << endl;
   cin >> Decision;
   chrono::duration<double, milli> elapsed_milliseconds;


    if (Decision == 0){
   fillarr(arr, n);
   cout << "Array before Sorting: ";
   display(arr, n);
   //START of running time
   start = chrono::steady_clock::now(); // make object start take a snapshot of the time before the merge sort
   mergeSort(arr, 0, n-1);     //(n-1) for last index
   end1 = chrono::steady_clock::now(); // make object start take a snapshot of the time after the selection sort
    //END of running time

   cout << "Array after Sorting: ";
   display(arr, n);
   cout <<"Elapsed time: " << elapsed_milliseconds.count() << "ms\n"; // diplay the time in milliseconds of the run time of selection sort on full sorted list
   cout << endl;
    }


    else if (Decision == 2){
   /* REVERSE SORT LIST */
   int c[n]; //create two arrays that will be reverse sorted for merge sort algorithm
   int r = 0; // start the index for the start of the array
   for(int i = n-1 ; i>=0; i--) // create a for loop that will begin at the end of the full-sorted list.
   {
     c[r] = arr[i]; //make the item starting at the end of array a the item at the start of array c. Go on until the first number of array a is the last number of array c
     r++; // increase the index of r
   }

   cout << "Reverse Sorted Array: ";
   display(c, n);
   //START of running time
   start = chrono::steady_clock::now(); // make object start take a snapshot of the time before the merge sort
   mergeSort(c, 0, n-1);     //(n-1) for last index
   end1 = chrono::steady_clock::now(); // make object start take a snapshot of the time after the selection sort
    //END of running time
   cout << "Array after Sorting: ";
   display(c, n);
   cout <<"Elapsed time: " << elapsed_milliseconds.count() << "ms\n"; // diplay the time in milliseconds of the run time of selection sort on full sorted list
   cout << endl;
    }

    else if(Decision == 3){
   /* HALF SORTED LIST */
   int d[n],d2[n]; // create two arrays that will be sorted for half and reverse sorted for the last half.
   int k=n/2; // create a size that is half the size of the input array
   for(int i =0; i<(n/2); i++) // go from the start of the array to half point fully sorted.
   {
	 d[i] = arr[i]; // copy the array a to array d until half way
     d2[i] = d[i]; // do the same for the array d2
   }
   for(int i = n-1; i>=(n/2); i--) // create for loop from the top size moving down the half way the size of the input array
   {
     d[k] = arr[i]; // copy the array starting from the end of array a to the middle going to the end of array d
     d2[k] = d[k]; // copy the same array starting from the same position for array d2
     k++; // increase the index that started at half the input array size
   }  ;

   /* HALF SORTED LIST SORTING ALGORITHMS */
   cout << "Half Sorted Array: ";
   display(d,n); // print the array before it is sorted.
   //START
   start = chrono::steady_clock::now(); // take the time before the selection sort
   mergeSort(d, 0, n-1);  //run the selection sort on the half-sorted list
   end1 = chrono::steady_clock::now(); // take the time after the selection sort
   //END
   elapsed_milliseconds = end1 - start; // calculate the time it took from start to end
   cout << "Merge Sorted array: \n";
   display(d, n); // Print the array after it has been sorted
   cout <<"Elapsed time: " << elapsed_milliseconds.count() << "ms\n"; //display the time it took to run
   cout << endl;
    }

}


