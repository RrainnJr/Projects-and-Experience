#include<iostream>
#include<chrono>

using namespace std;

void countingSort(int [], int [], int n, int);
void display(int [], int );
int MaxValue(int[] , int );
void RadixSort(int [], int, int);

    int Size = 100001;

int main(){
    chrono::time_point<chrono::steady_clock> start, end1;
    chrono::duration<double, milli> elapsed_milliseconds;


    int Arr[Size] = {0};
    int Sorted[Size-1];
    int d = 6;
    for (int i = 0; i <= 100000; i++){
        Arr[i] = rand()%10000;
    }
    int Max = MaxValue(Arr, Size);
    start = chrono::steady_clock::now();
    countingSort(Arr, Sorted, Size, Max);
    end1 = chrono::steady_clock::now();
    elapsed_milliseconds = end1-start;

    cout << "The counting sort ran in: " << elapsed_milliseconds.count() << "ms" << endl;

    //display(Sorted, Size);
    for (int i = 0; i <= 100000; i++){
        Arr[i] = rand()%10000;
    }

    start = chrono::steady_clock::now();
    RadixSort(Arr, Size, d);
    end1 = chrono::steady_clock::now();
    elapsed_milliseconds = end1-start;
    cout << "The Radix sort ran in: " << elapsed_milliseconds.count() << "ms" << endl;



    return 0;
}

void display(int Arr[], int Size){
    for (int i = 1; i <= Size; i++){
        cout << Arr[i] << ", ";
    }
    cout << endl;
}

void countingSort(int A[], int B[], int n, int k){
    int C[k+1] = {0};
    for (int i = 0; i <= k; i++){
        C[i] = 0;
    }
    for (int j = 0; j < n; j++){
        C[A[j]] = C[A[j]]+1;
    }
    for (int i = 0; i <= k; i++){
        C[i] = C[i] + C[i-1];
    }
    for (int j = n; j >= 0; j--){
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]]-1;
    }
}

int MaxValue(int Arr[], int Size){
    int MAX = 0;
    for (int i = 1; i <= Size; i++){
        if (Arr[i] > MAX){
            MAX = Arr[i];
        }
    }
    return MAX;
}

void RadixCountingSort(int A[], int B[], int n, int k, int i){
    int C[k+1] = {0};
    for (int j = 0; j <= k; j++){
        C[j] = 0;
    }
    for (int j = 0; j < n; j++){
        C[(A[j]%(10^(i+1)))/(10^(i+1))] = C[(A[j]%(10^(i+1)))/(10^(i+1))]+1;
    }
    for (int j = 0; j <= k; j++){
        C[j] = C[j] + C[j-1];
    }
    for (int j = n; j >= 0; j--){
        B[C[(A[j]%(10^(i+1)))/(10^(i+1))]] = A[j];
        C[(A[j]%(10^(i+1)))/(10^(i+1))] = C[(A[j]%(10^(i+1)))/(10^(i+1))]-1;
    }
}

void RadixSort(int a[], int n, int d) {
    int sortedArr[n];
    for (int i = 0; i <= d; i++) {
        RadixCountingSort(a, sortedArr, n, 9, i);
        a = sortedArr;
    }
    display(a, Size);
}
