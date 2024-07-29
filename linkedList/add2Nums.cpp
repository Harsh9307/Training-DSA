#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* next;
    int data;

    Node(int data1){
        data = data1;
        next=nullptr;
    }
};
// Node* createLL(vector<int>& arr);
Node* createLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    return head;
}
Node* reverse(Node* head){
    if(head==NULL || head->next == NULL) return head;

    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}
Node* add2Nums(Node* head1,Node* head2){
    Node* reversedHead1 = reverse(head1);
    Node* reversedHead2 = reverse(head2);

    Node* temp1 = reversedHead1;
    Node* temp2 = reversedHead2;

    Node* dummy = new Node(-1);
    Node* curr = dummy;
    int carry = 0;

    while(temp1 || temp2 || carry>0){
        int sum = carry;
        if (temp1 != nullptr) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2 != nullptr) {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        curr->next = new Node(sum % 10);
        carry = sum / 10;
        curr = curr->next;

    }
    Node* reversedHead = reverse(dummy->next);
    delete dummy;
    return reversedHead;

}
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    vector<int> arr1={1,2,3};
    vector<int> arr2={4,5,6};
    Node* head1 = createLL(arr1);
    Node* head2 = createLL(arr2);
    
    Node* head3 = add2Nums(head1,head2);
    print(head3);

    return 0;
}