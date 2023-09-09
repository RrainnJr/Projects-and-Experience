#include <iostream>

using namespace std;

void quicksort(int[], int , int );
int PartitionFirst(int[],int,int);
int PartitionMedian(int[],int,int);

int partitionChoice;
int AscDesc;
int SIZE;


void PrintArr(int Arr[], int size) {
   for(int i = 0; i<size; i++)
   cout << Arr[i] << " ";
   cout << endl;
}

int main (){

    char ChoiceEnter;
cout << "Insert the Size of the array: ";
cin >> SIZE;
int Arr[SIZE];
int x;

cout << endl << "Input an Array: " << endl;
for (int i = 0; i < SIZE; i++){
    cin >> x;
    Arr[i] = x;
}

int Exit = 0;
while(Exit == 0){
    cout << endl <<"Would you like to sort Ascending(a) or Descending(d) : ";
    cin >> ChoiceEnter;

    if (ChoiceEnter == 'a' || ChoiceEnter == 'A'){
        AscDesc = 0;
        Exit = 1;
    }
    else if (ChoiceEnter == 'd' || ChoiceEnter == 'D'){
        AscDesc = 1;
        Exit = 1;
    }
    else{
        cout << endl << "Invalid Choice, Try again" << endl;
    }
}
Exit = 0;

while (Exit == 0){
        cout << "Would you like a First Element(f), Random Element(r), or Median Element (m) pivot : ";
        cin >> ChoiceEnter;
        if (ChoiceEnter == 'f' || ChoiceEnter == 'F'){
            partitionChoice = 0;
            Exit = 1;
        }
        else if (ChoiceEnter == 'r' || ChoiceEnter == 'R'){
            partitionChoice = 1;
            Exit = 1;
        }
        else if (ChoiceEnter == 'm' || ChoiceEnter == 'M'){
            partitionChoice = 2;
            Exit = 1;
        }
        else {
            cout << endl << "Invalid Choice, Try again" << endl;
        }
}

quicksort(Arr, 0, SIZE);
PrintArr(Arr, SIZE);
return 0;
}


int Partition(int Arr[], int F, int B){
    int piv = Arr[F];
    int i = F-1;
    int j = B+1;
    int temp;

    /*for (int j = F; j<=B-1; j++)
        if (Arr[j] <= piv){
            i++;
            temp = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = temp;
        }
    temp = Arr[i+1];
    Arr[i+1] = Arr[B];
    Arr[B] = temp;*/

    while(true){
        do{
            i++;
        }while(Arr[i] < piv);
        do{
            j--;
        }while (Arr[j] > piv);
        if (i >= j){
            return j;
        }
        temp = Arr[i];
        Arr[i] = Arr[j];
        Arr[j] = temp;
    }


    return (i);
}

int PartitionRandom(int A[],int p,int r)
{
    int temp;
    int Idx = p + rand() % (r-p + 1);
    int x = A[Idx];
    int i = p-1;

    for(int j=p;j<r-1; j++){
        if(A[j] <= x)
        {
            i++;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }

    temp = A[i+1];
    A[i+1] = A[r-1];
    A[r-1] = temp;
    return i+1;
}

int PartitionFirst(int A[],int p,int r)
{
    int temp;
    int x = A[p];
    int p1 = p+1;
    for(int i=p+1;i<=r; i++){
        if(A[i] < x)
        {
            if(i!=p1){
                temp = A[p1];
                A[p1] = A[i];
                A[i] = temp;
            }
            p1++;
        }
    }
    A[p] = A[p1-1];
    A[p1-1] = x;
    cout << "Partition Called" << endl;
    return p1-1;
}

int PartitionMedian(int A[],int p,int r)
{
    int temp;
    int part = (((p + r)/2) + p + r)/2;
    int x = A[part];
    int p1 = part + 1;
    for(int i=part+1;i<=r; i++){
        if(A[i] < x)
        {
            if(i!=p1){
                temp = A[p1];
                A[p1] = A[i];
                A[i] = temp;
            }
            p1++;
        }
    }
    A[p] = A[p1-1];
    A[p1-1] = x;
    cout << "Partition Called" << endl;
    return p1-1;
}



void quicksort(int A[], int p, int r)
{
    int q;
    if(p<r)
    {
        if (partitionChoice == 0){
            q = PartitionFirst(A,p,r-1);
        }
        else if (partitionChoice == 1){
            q = PartitionRandom(A,p,r);
        }
        else if (partitionChoice == 2){
            q = PartitionMedian(A,p,r-1);
        }
    cout << "QuickSort Called" << endl;
        quicksort(A,p,q);
        quicksort(A,q+1,r);
    }
}
