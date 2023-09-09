// C++ implementation of a binary heap

#include <iostream>
#include <array>
#include <cmath>
using namespace std;


class Heap
{
    const static int MAX = 15;
    public:
    int Arr[MAX];
    int sizes;
    Heap(){
    sizes = 1;
    Arr[sizes-1] = -9999999;
    }
    void printArray(int Arr[],int n);
     //Max heap
    void modifyValMax (int Arr[], int n, int i,int val); //Modify value
    void insert_value_maxHeap (int Arr[], int val, int& n); //Adds value at the end of array and calls max_heapify
    void max_heapify(int Arr[], int i,int n); //Maintains the max heap property
    int extract_maximum (int Arr[], int& n); //Return the maximum element in heap and swap last element with first element
    void ascendingHeapSort(int Arr[], int n); //Prints the array in ascending order
    void buildMaxHeap(int Arr[], int n); //Heapifies entire list
    //Min Heap
    void modifyValMin (int Arr[], int n, int i,int val); //Modify value
    void insert_value_minHeap (int Arr[], int val, int& n); // Adds value at the end of array and calls min_heapify
    void min_heapify(int Arr[], int i, int n); //Maintains min heap property
    int extract_minimum (int Arr[], int& n); //Return the minimum element in heap and swap last element with first element
    void descendingHeapSort(int Arr[], int n); //Prints the array in descending order
    void buildMinHeap(int Arr[], int n); //Heapifies entire list
};
    // The print array function takes two inputs, (SAY INPUTS) and simply loops them and outpus each value in the current array
    void Heap::printArray(int Arr[],int n){
        for(int i = 0; i < n; i ++){
            cout << Arr[i] << " ";
        }
        cout << endl;
    }

    //Max heapify takes the array, index i and size, finds wether the value to the left or right is alrger and swaps the index at i with the larger value
    //If the largest is not the original index, we will also recursivly call Maxheapify to finish heapifying. if it is index I, it will exit

    void Heap::max_heapify(int Arr[], int i, int n){ //Maintains the max heap property
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest, temp;
        if(left <= n && Arr[left] > Arr[i])
            largest = left;
        else
            largest = i;
        if(right <= n && Arr[right] > Arr[largest])
            largest = right;
        if(largest != i){
            temp = Arr[i];
            Arr[i] = Arr[largest];
            Arr[largest] = temp;
            max_heapify(Arr, largest, n);
        }
    }

     //Max heap
    void Heap::modifyValMax(int Arr[], int n, int i,int val){
    if (i > n){
        cout << "Modification Failed, i is Out of Range" << endl;
    }
    else {
        Arr[i] = val;
    }
    max_heapify(Arr, i, n);
    }


    void Heap::insert_value_maxHeap (int Arr[], int val, int& n){ //Adds value at the end of array and calls max_heapify
    Arr[n] = -999999999;
    //n = n+1;
    modifyValMax(Arr, n, n, val);
    sizes++;
    }


    int Heap::extract_maximum (int Arr[], int& n){ //Return the maximum element in heap and swap last element with first element
        if(n < 0)
            cout << "Heap Underflow";
        else{
            buildMaxHeap(Arr, n);
            int maxs = Arr[0];
            Arr[0] = Arr[n-1];
            max_heapify(Arr,0,n-2);
            sizes--;
            return maxs;
        }
    }

    void Heap::buildMaxHeap(int Arr[], int n){ //Heapifies entire list
            for(int i = (n/2); i >= 0; i--){
                max_heapify(Arr, i, n-1);
            }
    }

    void Heap::ascendingHeapSort(int Arr[], int n){
        buildMaxHeap(Arr, n);
        int temp;
            for (int i = n-1; i >= 1; i--){
                temp = Arr[0];
                Arr[0] = Arr[i];
                Arr[i] = temp;
                max_heapify(Arr, 0, i-1);
            }
    }




    //Min Heap
    void Heap::min_heapify(int Arr[], int i, int n){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest, temp;
        if(left <= n && Arr[left] < Arr[i])
            smallest = left;
        else
            smallest = i;
        if(right <= n && Arr[right] < Arr[smallest])
            smallest = right;
        if(smallest != i){
            temp = Arr[i];
            Arr[i] = Arr[smallest];
            Arr[smallest] = temp;
            min_heapify(Arr, smallest, n);
        }
    } //Maintains min heap property


    void Heap::modifyValMin(int Arr[], int n, int i,int val){
    if (i > n){
        cout << "Modification Failed, i is Out of Range" << endl;
    }
    else {
        Arr[i] = val;
    }
    min_heapify(Arr, i, n);
    }

    void Heap::insert_value_minHeap (int Arr[], int val, int& n){
        Arr[n] = 999999999;
        //n = n+1;
        modifyValMin(Arr, n, n, val);
        sizes++;
    } // Adds value at the end of array and calls min_heapify

    int Heap::extract_minimum (int Arr[], int& n){
        if(n < 0)
            cout << "Heap Underflow";
        else{
            buildMinHeap(Arr, n);
            int mini = Arr[0];
            Arr[0] = Arr[n-1];
            min_heapify(Arr,0,n-2);
            sizes--;
            return mini;
        }
    } //Return the minimum element in heap and swap last element with first element

    void Heap::descendingHeapSort(int Arr[], int n){
    buildMinHeap(Arr, n);
    int temp;
        for (int i = n-1; i >= 0; i--){
            temp = Arr[0];
            Arr[0] = Arr[i];
            Arr[i] = temp;
            min_heapify(Arr, 0, i-1);
        }
    }

    void Heap::buildMinHeap(int Arr[], int n){ //Heapifies entire list
        for(int i = (n/2); i >= 0; i--){
                min_heapify(Arr, i, n-1);
            }
    }


int main() {
    int x;
    Heap heap;
    /*heap.printArray(heap.Arr, heap.sizes);
    heap.modifyValMax(heap.Arr, heap.sizes, 0, 5);
    for(int i = 6; i < 20; i++){
        heap.insert_value_maxHeap(heap.Arr, i, heap.sizes);
    }
    heap.printArray(heap.Arr, heap.sizes);
    heap.buildMaxHeap(heap.Arr, heap.sizes);
    heap.printArray(heap.Arr, heap.sizes);
    heap.ascendingHeapSort(heap.Arr, heap.sizes);
    heap.printArray(heap.Arr, heap.sizes);
    x = heap.extract_maximum(heap.Arr, heap.sizes);
    cout << "The max is " << x << endl;
    //heap.ascendingHeapSort(heap.Arr, heap.sizes);
    heap.printArray(heap.Arr, heap.sizes);

    cout << "Building min heap: " << endl;
    heap.buildMinHeap(heap.Arr, heap.sizes);
    heap.printArray(heap.Arr, heap.sizes);
    cout << "Sorting in Descending: " << endl;
    heap.descendingHeapSort(heap.Arr, heap.sizes);
    heap.printArray(heap.Arr, heap.sizes);
    cout << "Extracting Minimum: " << endl;
    x = heap.extract_minimum(heap.Arr, heap.sizes);
    cout << "The minimum is: " << x << endl;
    heap.printArray(heap.Arr, heap.sizes);
    */
    int MinOrMax, Extract, Print, Val, SIZE;
    while (1){
    cout << "Insert the Size of the array: ";
    cin >> SIZE;

    cout << endl << "Input an Array: " << endl;
    cin >> x;
    heap.modifyValMax(heap.Arr, heap.sizes, 0, x);
    for (int i = 1; i < SIZE; i++){
        cin >> x;
        heap.insert_value_maxHeap(heap.Arr, x, heap.sizes);
    }
    cout << "Would you like to sort in a min(enter 1) or max(enter 2) heap: " << endl;
    cin >> MinOrMax;
    cout << "The heapified list: ";
    //heap.printArray(heap.Arr, heap.sizes);
    if (MinOrMax == 1){
        heap.buildMinHeap(heap.Arr, heap.sizes);
        heap.printArray(heap.Arr, heap.sizes);
        cout << "The descending heap sorted list: " << endl;
        heap.descendingHeapSort(heap.Arr, heap.sizes);
        heap.printArray(heap.Arr, heap.sizes);
    }
    else if (MinOrMax == 2){
        heap.buildMaxHeap(heap.Arr, heap.sizes);
        heap.printArray(heap.Arr, heap.sizes);
        cout << endl << "The ascending heap sorted list: " << endl;
        heap.ascendingHeapSort(heap.Arr, heap.sizes);
        heap.printArray(heap.Arr, heap.sizes);
    }
    else {
        cout << endl << "ERROR: INVALID CHOICE";
    }

    cout << "Would you like to extract a min or max value?" << endl << "No (0) " << endl << "Min (1) " << endl << "Max(2)" << endl;
    cin >> Extract;
    if (Extract == 0){
    }
    else if (Extract == 1){
        heap.extract_minimum(heap.Arr, heap.sizes);
    }
    else if (Extract == 2){
        heap.extract_maximum(heap.Arr, heap.sizes);
    }
    else {
        cout << "ERROR: INVALID INPUT";
    }

    cout << endl << "The current Heap: ";
    heap.printArray(heap.Arr, heap.sizes);

    cout << "Would you like to print the minimum and max value?" << endl << "0: No" << endl << "1: Yes" << endl;
    cin >> Print;
    if (Print == 0){
    }
    else if (Print == 1){
        heap.buildMaxHeap(heap.Arr, heap.sizes);
        heap.descendingHeapSort(heap.Arr, heap.sizes);
        cout << "Maximum Value : " << heap.Arr[0] << endl;
        cout << "Minimum Value : " << heap.Arr[heap.sizes-1] << endl;
    }

    cout << "Would you like to add elements to the array?" << endl;
    cout << "Value: ";
    cin >> Val;
    if (MinOrMax == 1){
        heap.insert_value_minHeap(heap.Arr, Val, heap.sizes);
    }
    else if (MinOrMax == 2){
        heap.insert_value_maxHeap(heap.Arr, Val, heap.sizes);
    }
    cout << endl << "The current Heap: ";
    heap.printArray(heap.Arr, heap.sizes);
    }
    return 0;
}
