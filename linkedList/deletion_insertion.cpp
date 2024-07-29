#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* next;
        int data;

    public:
        Node(int data){
            this->data = data;
            next = nullptr;
        }
};

void printLL(Node *head){
    if(head == NULL) {
        cout<<"Linked List is empty!"<<endl;
    }
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insertEleAtK(Node *head, int pos , int data){
    if(head == NULL) { //if there are no nodes in LL
        if(pos == 1) head= new Node(data);
        else cout<<"Position out of bounds!"<<endl;
        return;
    }
    // head is not null
    if(pos == 1) {
        // create a new node
        Node* node = new Node(data);
        node->next = head;
        head = node;
        return;
    }
   
    Node* temp = head;
    for(int i=1;i<pos-1 and temp != nullptr ;i++){
        temp=temp->next;
    }
    if(temp == nullptr) cout<<"Position out of bounds!"<<endl;
    else {
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next=newNode;
    }    
}


int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    printLL(head);
    insertEleAtK(head,9,9);   // {head,position,data}
    printLL(head);
    
    return 0;
}