#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>

using namespace std;
using namespace std::chrono;

void selection(vector<int>);
void bubble(vector<int>);
void printVec(vector<int>);
vector<int> fillVec(string);

int main() {
    vector<int> ToSort = {};

    string FileName = "InputRand.txt";
    ToSort = fillVec(FileName);

    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    ofstream selectionF;
    selectionF.open("Selection.txt", ios::out);

    ofstream bubbleF;
    bubbleF.open("Bubble.txt", ios::out);

    int BubbTot = 0;
    int SelTot = 0;

    for (int n = 0; n < 20; n++){ //Takes the average time in microseconds from 20 iterations of a 1000 element Random vector to execute bubble and Selection Sort.
    start = high_resolution_clock::now();
    bubble(ToSort);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    BubbTot = BubbTot + duration.count();
    start = high_resolution_clock::now();
    selection(ToSort);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    SelTot = SelTot + duration.count();
    }

    cout << "The average time for a Random input of 1000 elements is: " << endl;
    cout << "     Bubble Sort: " << BubbTot/20 << " Microseconds" << endl;
    cout << "     Selection Sort: " << SelTot/20 << " Microseconds" << endl << endl;

    BubbTot = 0;
    SelTot = 0;

    FileName = "inputRevSorted.txt";
    ToSort = fillVec(FileName);

    for (int n = 0; n < 20; n++){ //Takes the average time in microseconds from 20 iterations of a 1000 element reverse sorted vector to execute bubble and Selection Sort.
    start = high_resolution_clock::now();
    bubble(ToSort);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    BubbTot = BubbTot + duration.count();

    start = high_resolution_clock::now();
    selection(ToSort);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    SelTot = SelTot + duration.count();
    }

    cout << "The average time for a Reverse Sorted input of 1000 elements is: " << endl;
    cout << "     Bubble Sort: " << BubbTot/20 << " Microseconds" << endl;
    cout << "     Selection Sort: " << SelTot/20 << " Microseconds" << endl << endl;

    BubbTot = 0;
    SelTot = 0;

    FileName = "inputsorted.txt";
    ToSort = fillVec(FileName);

    for (int n = 0; n < 20; n++){ //Takes the average time in microseconds from 20 iterations of a 1000 element sorted vector to execute bubble and Selection Sort.
    start = high_resolution_clock::now();
    bubble(ToSort);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    BubbTot = BubbTot + duration.count();

    start = high_resolution_clock::now();
    selection(ToSort);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    SelTot = SelTot + duration.count();
    }

    cout << "The average time for a Sorted input of 1000 elements is: " << endl;
    cout << "     Bubble Sort: " << BubbTot/20 << " Microseconds" << endl;
    cout << "     Selection Sort: " << SelTot/20 << " Microseconds" << endl << endl;

    BubbTot = 0;
    SelTot = 0;

    FileName = "InputHalfSorted.txt";
    ToSort = fillVec(FileName);

    for (int n = 0; n < 20; n++){ //Takes the average time in microseconds from 20 iterations of a 1000 element Half Sorted vector to execute bubble and Selection Sort.
    start = high_resolution_clock::now();
    bubble(ToSort);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    BubbTot = BubbTot + duration.count();

    start = high_resolution_clock::now();
    selection(ToSort);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    SelTot = SelTot + duration.count();
    }

    cout << "The average time for a Half Sorted input of 1000 elements is: " << endl;
    cout << "     Bubble Sort: " << BubbTot/20 << " Microseconds" << endl;
    cout << "     Selection Sort: " << SelTot/20 << " Microseconds" << endl << endl;

    BubbTot = 0;
    SelTot = 0;

    for (int i = 0; i < 1000; i++){ //Takes the average time of all input sizes from 0 to 1000 and sends them to output file
        ifstream input;
        vector<int> FullVec = {0};
        int j = 0;
        input.open("InputRand.txt", ios::in);
    while(j != i){
        input >> FullVec.at(j);
        j++;
        FullVec.resize(FullVec.size()+1);
    }
        FullVec.resize(FullVec.size()-1);
        input.close();

    for (int n = 0; n < 20; n++){
    start = high_resolution_clock::now();
    bubble(ToSort);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //bubbleF << duration.count() << endl;
    BubbTot = BubbTot + duration.count();

    start = high_resolution_clock::now();
    selection(ToSort);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //selectionF << duration.count() << endl;
    SelTot = SelTot + duration.count();
    }
    selectionF << SelTot/20 << endl;
    bubbleF << BubbTot/20 << endl;
    }

    selectionF.close();
    bubbleF.close();
    return 0;
}

void selection(vector<int> ToSort){
    int temp = 0;
    int minj = 0;
    int n = ToSort.size();
    for (int j = 0; j < n-1; j++){
        minj = j;
            for (int i = j; i <= n-1; i++){
                if (ToSort[i] < ToSort[minj])
                    minj = i;
            }
            temp = ToSort[minj];
            ToSort[minj] = ToSort[j];
            ToSort[j] = temp;
    }
    //printVec(ToSort);
    return;
}

void bubble(vector<int> ToSort){
    int temp = 0;
    for (int i = 0; i <= ToSort.size(); i++){
        for (int j = ToSort.size()-1; j > i; j--){
            if (ToSort[j] < ToSort[j-1]){
                temp = ToSort[j];
                ToSort[j] = ToSort[j-1];
                ToSort[j-1] = temp;
            }
        }
    }
    //printVec(ToSort);
    return;
}

void printVec(vector<int> vec){
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << ", ";
    }
    cout << endl;
}

vector<int> fillVec(string fName){
    vector<int> FullVec = {0};
    ifstream input;
    int i = 0;
    int temp = 0;
    input.open(fName, ios::in);
    input >> temp;
    while(temp != -1){
        FullVec.at(i) = temp;
        input >> temp;
        i++;
        FullVec.resize(FullVec.size()+1);
    }
    FullVec.resize(FullVec.size()-1);
    //printVec(FullVec);
    input.close();
    return FullVec;
}
