#include<iostream>
#include <chrono>
#include <ctime>
using namespace std;

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
   cout << array[i] << " ";
   cout << endl;
}

//merge is O(n)
void merges(int arr[], int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = arr[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = arr[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         arr[k] = larr[i];
         i++;
      }else{
         arr[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      arr[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      arr[k] = rarr[j];
      j++; k++;
   }
}


void mergeSort(int arr[], int l, int r) {
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merges(arr, l, m, r);
   }
}

//function that performs insertion sort and displays sorting time
void insertion(int arr[], int leng){
     auto starti = chrono::steady_clock::now();
     int key,i,temp;
     for(int j = 1; j < leng; j++){
        key = arr[j];
        i = j-1;
        while(i > 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i = i -1;
        }
        arr[i+1] = key;
     }
     auto Endi = chrono::steady_clock::now();
    cout << "Elapsed time for insertionSort: "
        << chrono::duration_cast<chrono::nanoseconds>(Endi - starti).count()
        << " ns" << endl;
}

//function to perform bubble sort on a list and display the sorting time
void bubble(int arr[], int leng){
    int temp;
    auto startb = chrono::steady_clock::now();
    for(int i = 0; i < leng; i++){
        for(int j = leng-1; j > i; j--){
            if(arr[j] < arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    auto Endb = chrono::steady_clock::now();
    //cout << endl << "Array after Sorting: ";
   //display(arr, leng);
   cout << endl;
    cout << "Elapsed time for bubbleSort: "
        << chrono::duration_cast<chrono::nanoseconds>(Endb - startb).count()
        << " ns" << endl;
}

//function to perform selection sort on a list and display the sorting time
void select(int arr[], int leng){
    int small, temp;
    auto starts = chrono::steady_clock::now();
    for(int j = 0; j < leng; j++){
        small = j;
        for(int i = j; i < leng; i++){
            if(arr[i] < arr[small])
                small = i;
        }
        temp = arr[j];
        arr[j] = arr[small];
        arr[small] = temp;
    }
    auto Ends = chrono::steady_clock::now();
    //cout << endl << "Array after Sorting: ";
   //display(arr, leng);
   cout << endl;
    cout << "Elapsed time for selcectionSort: "
        << chrono::duration_cast<chrono::nanoseconds>(Ends - starts).count()
        << " ns" << endl;
}

//function that performs insertion sort and displays sorting time
void insertionSort(int *arr, int leng){
     int key,i; //Initialization Prior, arr[0]'
     //cout << "Initialization phase, current array is: " << arr[0] << endl;
     for(int j = 1; j < leng; j++){
        key = arr[j];
        i = j-1;
        //Maintenance, Looping through the array, finding where the new value fits.
        while(i >= 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i = i -1;
        }
        arr[i+1] = key;
        //cout << endl << "Sublist should now be sorted, maintenance has been complete for: ";
        //display(arr, j+1);
     }
     //cout << endl << "Termination of Insertion sort when array is sorted: ";
     //display(arr, leng);
     //Termination, The program ends after the last value of the array has been sorted.
        //Sorted permutation of original list
}

void fillarr(int *arr, int n){
    for (int i = 0; i < n; i++){
        arr[i] = rand();
    }
    return;
}

void Copier(int* Master, int *Copy, int n){
    for(int i = 0; i < n; i++){
        Copy[i] = Master[i];
    }
}

int main() {
   int n;
   chrono::time_point<chrono::steady_clock> start, end1; // create two time_point objects start and end1.
   chrono::duration<double, nano> elapsed_milliseconds,total_time; //create a duration of milliseconds that is the time from start to end.
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];
   int Decision;
   cout << "Would you like to see Runtime for: " << endl << "     1: Pre-Sorted "
<< endl << "     2: Reverse Sorted" << "     3: Half-Sorted " << endl;
   cin >> Decision;
   fillarr(arr, n);
   //insertionSort(arr,n);


    if(Decision == 1){
   /*PRE SORTED LIST*/
   cout << endl << "Pre Sorted Array: ";
   //display(arr, n);
   start = chrono::steady_clock::now(); // make object start take a snapshot of the time before the merge sort
   insertionSort(arr, n);     //(n-1) for last index
   end1 = chrono::steady_clock::now(); // make object start take a snapshot of the time after the selection sort
    //END of running time
   elapsed_milliseconds = end1 - start; //create a duration of milliseconds that is the time from start to end.
   //cout << endl << "Array after Sorting: ";
   //display(arr, n);
   cout << endl << "Elapsed time for insertionSort: " << elapsed_milliseconds.count() << "ns\n"; //display the time it took to run
   start = chrono::steady_clock::now(); // make object start take a snapshot of the time before the merge sort
   //mergeSort(arr, 0, n-1);     //(n-1) for last index
   end1 = chrono::steady_clock::now(); // make object start take a snapshot of the time after the selection sort
    //END of running time
   elapsed_milliseconds = end1 - start; //create a duration of milliseconds that is the time from start to end.
   //cout << endl << "Array after Sorting: ";
   //display(arr, n);
   cout << endl << "Elapsed time for MergeSort: " << elapsed_milliseconds.count() << "ns\n"; //display the time it took to run
   //bubble(arr,n);
   //select(arr,n);
   cout << endl;
    }


    else if(Decision == 2){
   /* REVERSE SORT LIST */
   int c[n],temp[n]; //create two arrays that will be reverse sorted for merge sort algorithm
   int r = 0; // start the index for the start of the array
   for(int i = n-1 ; i>=0; i--) // create a for loop that will begin at the end of the full-sorted list.
   {
     c[r] = arr[i]; //make the item starting at the end of array a the item at the start of array c. Go on until the first number of array a is the last number of array c
     r++; // increase the index of r
   }
   cout << endl << "Reverse Sorted Array: ";
   display(c, n);
   Copier(c,temp,n);
   //START of running time
   start = chrono::steady_clock::now(); // make object start take a snapshot of the time before the merge sort
   insertionSort(temp, n);     //(n-1) for last index
   end1 = chrono::steady_clock::now(); // make object start take a snapshot of the time after the selection sort
    //END of running time
    elapsed_milliseconds = end1 - start; //create a duration of milliseconds that is the time from start to end.
    //cout << endl << "Array after Sorting: ";
   //display(temp, n);
   cout << endl << "Elapsed time for insertionSort: " << elapsed_milliseconds.count() << "ns\n"; //display the time it took to run
   Copier(c,temp,n);
   start = chrono::steady_clock::now(); // make object start take a snapshot of the time before the merge sort
   mergeSort(temp, 0, n-1);     //(n-1) for last index
   end1 = chrono::steady_clock::now(); // make object start take a snapshot of the time after the selection sort
    //END of running time
   elapsed_milliseconds = end1 - start; //create a duration of milliseconds that is the time from start to end.
   //cout << endl << "Array after Sorting: ";
   //display(temp, n);
   cout << endl << "Elapsed time for MergeSort: " << elapsed_milliseconds.count() << "ns\n"; //display the time it took to run
   Copier(c,temp,n);
   bubble(temp,n);
   Copier(c,temp,n);
   select(temp,n);
   cout << endl;
    }


    else if(Decision == 3){
   /* HALF SORTED LIST */
   int d[n],d2[n],temp[n]; // create two arrays that will be sorted for half and reverse sorted for the last half.
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
   cout << endl << "Half Sorted Array: ";
   display(d,n); // print the array before it is sorted.
   //START
   Copier(d,temp,n);
   //START of running time
   start = chrono::steady_clock::now(); // make object start take a snapshot of the time before the merge sort
   insertionSort(temp, n);     //(n-1) for last index
   end1 = chrono::steady_clock::now(); // make object start take a snapshot of the time after the selection sort
    //END of running time
    elapsed_milliseconds = end1 - start; //create a duration of milliseconds that is the time from start to end.
    //cout << endl << "Array after Sorting: ";
    //display(temp, n);
   cout << endl << "Elapsed time for insertionSort: " << elapsed_milliseconds.count() << "ns\n"; //display the time it took to run
   Copier(d,temp,n);
   start = chrono::steady_clock::now(); // make object start take a snapshot of the time before the merge sort
   mergeSort(temp, 0, n-1);     //(n-1) for last index
   end1 = chrono::steady_clock::now(); // make object start take a snapshot of the time after the selection sort
    //END of running time
   elapsed_milliseconds = end1 - start; //create a duration of milliseconds that is the time from start to end.
    //cout << endl << "Array after Sorting: ";
    //display(temp, n);
   cout << endl << "Elapsed time for MergeSort: " << elapsed_milliseconds.count() << "ns\n"; //display the time it took to run
   Copier(d,temp,n);
   bubble(temp,n);
   Copier(d,temp,n);
   select(temp,n);
   cout << endl;
    }
}
