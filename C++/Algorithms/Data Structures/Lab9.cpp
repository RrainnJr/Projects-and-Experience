#include<iostream>
#include<cmath>
#include<chrono>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val = 0, Node* nxt = nullptr) {
        data = val;
        next = nxt;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int Max_size;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void FillLinkedList(int);
    void DeleteLinked();
    bool isEmpty();
    bool isFull();
    void printList();

};

class Stack{
public:
    LinkedList LLS;
    int CurrSize;
    void push(int Val);
    int pop();
    void printStack(){
        LLS.printList();
    }
};

class Queue{
public:
    int CurrSize;
    LinkedList LLQ;
    void enqueue(int);
    int dequeue();

};

void Queue::enqueue(int x){
    if(LLQ.Max_size <= CurrSize){
        cout << endl << "No room to Enqueue!";
        return;
    }
    Node* New = new Node;
    New->data = x;
    New->next = nullptr;
    if (LLQ.tail == nullptr){
        LLQ.tail = New;
        LLQ.head = New;
    }
    else {
        LLQ.tail->next = New;
        LLQ.tail = New;
    }
    CurrSize++;
}

int Queue::dequeue() {
    int Return = 0;
    if (LLQ.head == nullptr) {
        cout << "list is empty" << endl;
    }
    else if (LLQ.head->next == nullptr){
        Return = LLQ.head->data;
        LLQ.head = nullptr;
        LLQ.tail = nullptr;
    }
    else {
        Node* temp = LLQ.head->next;
        Return = LLQ.head->data;
        delete LLQ.head;
        LLQ.head = temp;
    }
    CurrSize--;
return Return;
}

void Stack::push(int Val){
    if(LLS.Max_size <= CurrSize){
        cout << endl << "No room to Push!";
        return;
    }
    Node* New = new Node;
    New->data = Val;
    if (LLS.head == nullptr){
        LLS.head = New;
        LLS.tail = New;
    }
    else{
        New->next = LLS.head;
        LLS.head = New;
    }
    CurrSize++;
}

int Stack::pop(){
    if(LLS.head == nullptr){
        cout << endl << "NOTHING TO POP" << endl;
        return -1;
    }
    int temp = LLS.head->data;
    Node* TempNode = LLS.head;
    LLS.head = LLS.head->next;
    delete TempNode;
    return temp;
    CurrSize--;
}

bool LinkedList::isEmpty(){
    if(head == nullptr){
        return true;
    }
    return false;
}


void LinkedList::FillLinkedList(int N){
    int val;

    for (int i = 0; i < N; i++){
        val = rand()%100;
    if (i == 0) {
        Node* newNode = new Node(val, head);
        head = newNode;
    }
    else {
        Node* newNode = new Node(val);
        Node* currNode = head;
        for (int i = 0; i < i - 1 && currNode != nullptr; i++) {
            currNode = currNode->next;
        }
        if (currNode == nullptr) {
            std::cout << "Index out of bounds!" << std::endl;
        } else {
            newNode->next = currNode->next;
            currNode->next = newNode;
        }
    }
}

}

void LinkedList::printList(){
    Node* newNode = head;
    while (newNode->next != nullptr){
        cout << newNode->data << ", ";
    }
    cout << endl;
}

void LinkedList::DeleteLinked() {
    Node* currNode = head;
    while (currNode != nullptr) {
        Node* tempNode = currNode;
        currNode = currNode->next;
        delete tempNode;
    }
    head = nullptr;
    tail = nullptr;
}

void FillArray(int N){
    int Size = N*1024;
    int* Arr = (int*)malloc(Size * sizeof(int));

    int val;
    for (int i = 0; i < Size; i++){
        val = rand()%100;
        Arr[i] = val;
    }

    free(Arr);
    ;
}



int main(){
    int N;
    LinkedList Link;
    Queue Q;
    Stack S;

    int decision, maxsize, Exit, Value, Flag;
    cout << "Would you like to have a Stacking Using Queue implementation (2) Stack(1) or a Queue(0)" << endl;
    cin >> decision;
    cout << "Enter the Max Size of your Array : ";
    cin >> maxsize;


    if (decision == 1){
        S.LLS.Max_size = maxsize;

        while (Exit == 0){
            while(Flag != 1){
                cout << endl << "Enter the Value you would like to push, or enter 0" << endl;
                cin >> Value;
                if (Value != 0){
                    S.push(Value);
                }
                else {
                    Flag = 1;
                }
            }

            while(Flag != 0){
                cout << endl << "Would you like to Pop? (1) Yes (0) No";
                cin >> Value;
                if(Value == 1){
                    cout << endl << "You have Popped: " << S.pop() << endl;
                }
                else{
                    Flag = 0;
                }
            }
            cout << "Enter 0 to Exit: " << endl;
            cin >> Exit;
        }

    }

    else if (decision == 0){
        Q.LLQ.Max_size = maxsize;
        Q.CurrSize = 0;

        while (Exit == 0){
            while(Flag != 1){
                cout << endl << "Enter the Value you would like to Enqueue, or enter 0" << endl;
                cin >> Value;
                if (Value != 0){
                    Q.enqueue(Value);
                }
                else {
                    Flag = 1;
                }
            }

            while(Flag != 0){
                cout << endl << "Would you like to Pop? (1) Yes (0) No";
                cin >> Value;
                if(Value == 1){
                    cout << endl << "You have Popped: " << Q.dequeue() << endl;
                }
                else{
                    Flag = 0;
                }
            }
            cout << "Enter 0 to Exit: " << endl;
            cin >> Exit;
        }
    }
    else if (decision == 2){
        Queue Q1;
        Queue Q2;
        Q1.LLQ.Max_size = maxsize;
        Q1.CurrSize = 0;
        Q2.LLQ.Max_size = maxsize;
        Q2.CurrSize = 0;

        while (Exit == 0){
            while(Flag != 1){
                cout << endl << "Enter the Value you would like to Enqueue, or enter 0" << endl;
                cin >> Value;
                if (Value != 0){
                    if(Q1.LLQ.isEmpty()){
                        Q1.enqueue(Value);
                        while(!Q2.LLQ.isEmpty()){
                            Q1.enqueue(Q2.dequeue());
                        }
                    }
                    else if(Q2.LLQ.isEmpty()){
                        Q2.enqueue(Value);
                        while(!Q1.LLQ.isEmpty()){
                            Q2.enqueue(Q1.dequeue());
                        }
                    }
                }
                else {
                    Flag = 1;
                }
            }

            while(Flag != 0){
                cout << endl << "Would you like to Pop? (1) Yes (0) No";
                cin >> Value;
                int popped;

                if(Value == 1){
                    if (!Q1.LLQ.isEmpty()){
                        popped = Q1.dequeue();
                    }
                    else if (!Q2.LLQ.isEmpty()){
                        popped = Q2.dequeue();
                    }
                    cout << endl << "You have Popped: " << popped << endl;
                }
                else{
                    Flag = 0;
                }
            }
            cout << "Enter 0 to Continue: " << endl;
            cin >> Exit;
        }
    }

    chrono::time_point<chrono::steady_clock> start, end1;
    chrono::duration<double, milli> elapsed_milliseconds;


return 0;
}

