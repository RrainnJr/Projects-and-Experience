#include <iostream>
#include <cmath>

using namespace std;
class Heap
{
    const static int MAX = 15;
    public:
    int Arr[MAX];
    int sizes;
    Heap(){
    sizes = 0;
    Arr[sizes] = -9999999;
    }
    void printArray(int Arr[],int n){
        for(int i = 0; i < n; i ++){
            cout << Arr[i] << " ";
        }
        cout << endl;
    }
     //Max heap
    void modifyValMax(int Arr[], int n, int i,int val){
    if (i > n){
        cout << "Modification Failed, i is Out of Range" << endl;
    }
    else {
        Arr[i] = val;
    }
    max_heapify(Arr, i, n);
    }

    void insert_value_maxHeap (int Arr[], int val, int& n){ //Adds value at the end of array and calls max_heapify
    n = n+1;
    Arr[n] = -999999999;
    modifyValMax(Arr, n, n-1, val);
    sizes++;
    }

    void max_heapify(int Arr[], int i,int n){ //Maintains the max heap property
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
        }
    }

    int extract_maximum (int Arr[], int& n){ //Return the maximum element in heap and swap last element with first element
        if(n < 0)
            cout << "Heap Underflow";
        else{
            int maxs = Arr[0];
            Arr[0] = Arr[n-1];
            max_heapify(Arr,0,n-2);
            sizes = n-1;
        }
    }

    void ascendingHeapSort(int Arr[], int n){
    buildMaxHeap(Arr, n);
    int temp;
        for (int i = n; i >= 1; i++){
            temp = Arr[1];
            Arr[1] = Arr[i];
            Arr[i] = temp;
            max_heapify(Arr, 1, i-1);
        }
}

    void buildMaxHeap(int Arr[], int n){ //Heapifies entire list
        for(int i = floor(n/2); i >= 0; i--){
            max_heapify(Arr, i, n);
        }
    }



    //Min Heap
    void modifyValMin(int Arr[], int n, int i,int val){
    if (i > n){
        cout << "Modification Failed, i is Out of Range" << endl;
    }
    else {
        Arr[i] = val;
    }
    min_heapify(Arr, i, n);
    }

    void insert_value_minHeap (int Arr[], int val, int& n); // Adds value at the end of array and calls min_heapify
    void min_heapify(int Arr[], int i, int n); //Maintains min heap property
    int extract_minimum (int Arr[]); //Return the minimum element in heap and swap last element with first element

    void descendingHeapSort(int Arr[], int n){
    buildMinHeap(Arr, n);
    int temp;
        for (int i = n; i >= 1; i++){
            temp = Arr[0];
            Arr[0] = Arr[i];
            Arr[i] = temp;
            min_heapify(Arr, 0, i-1);
        }
    }

    void buildMinHeap(int Arr[], int n); //Heapifies entire list
};
