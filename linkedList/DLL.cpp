#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;

    public:
        Node(int data){
            this->data = data;
            next = nullptr;
            back = nullptr;
        }
        Node(int data1,Node* next1,Node* back1){
            data=data1;
            next=next1;
            back=back1;
        }
};
Node* convertArrtoDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev=temp;
    }
    return head;
}
Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head=head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next){
        temp=temp->next;
    }
    Node *prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
Node* deleteKthNode(Node* head,int k){
    if(head == NULL ) return NULL;
    int cnt=0;
    Node* temp = head;
    while(temp){
        cnt++;
        temp=temp->next;
        if(cnt==k) break;
    }
    if(temp->next == NULL and temp->back == NULL){
        delete temp;
        return NULL;
    }
    else if(temp->next==NULL){
        return deleteTail(head);
    }
    else if(temp->back==NULL){
        return deleteHead(head);
    }
    else {    
        Node* prev = temp->back;
        Node* front = temp->next;

        prev->next = front;
        front->back = prev;

        temp->next=nullptr;
        temp->back =nullptr;

        delete temp;
        return head;
    }
}
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node* insertBeforeHead(Node* head,int data){
    if(head == NULL) return new Node(data);

    Node* newHead = new Node(data,head,nullptr);
    head->back = newHead;
    head=newHead;

    return head;
}
Node* insertBeforeTail(Node* head,int data){
    Node* tail = head;
    while(tail->next){
        tail=tail->next;
    }
    Node* node = new Node(data,tail,tail->back);
    tail->back->next = node;
    return head;
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node* head =convertArrtoDLL(arr);
    //head = deleteHead(head);
    //head = deleteTail(head);
    //head=deleteKthNode(head,4);
    //head = insertBeforeHead(head,9);
    head = insertBeforeTail(head,10);
    print(head);
    return 0;
}