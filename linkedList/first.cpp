#include <bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data; 
    Node* next; 
    
    Node(int data1, Node* next1) {
        data = data1;  
        next = next1;  
    }

    Node(int data1) {
        data = data1;  
        next = nullptr;  
    }

    Node() : data(0), next(nullptr) {} // Default constructor
};

Node* head = nullptr; // Global declaration of head

void createLL(int value) {
    if (head == nullptr) {
        head = new Node(value);
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(value);
}

void putNodeInFront(int value) {
    Node* temp = new Node(value);
    temp->next = head;
    head = temp;
}

void removeLast() {
    if (head == nullptr) {
        cout << "Linked List is empty" << endl;
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;
    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;    
    }

    if (prev == nullptr) { // Only one element in the list
        delete head;
        head = nullptr;
    } else {
        prev->next = nullptr;
        delete curr;
    }
}

void removeFirst(){
    if(head == nullptr){
        cout<<"LL is already empty!"<<endl;
        return;
    }
    Node* temp=head;
    head = head->next;
    delete temp;
}

void findSize()
int main() {
    vector<int> arr = {};

    for (int i = 0; i < arr.size(); i++) {
        createLL(arr[i]);
    }
    //putNodeInFront(4);
    //removeLast();
    removeFirst();
    // Print the linked list to verify
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
