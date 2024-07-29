#include <bits/stdc++.h>
using namespace std;
int maxi = INT_MIN;
int mini = INT_MAX;
// Structure of the node of a binary tree
struct Node {
    int val;
    struct Node *left, *right;

    Node(int data)
    {
        this->val = data;
        left = right = NULL;
    }
};

int width(Node* root,int level){
    if(root == NULL) return 0;
    int left =width(root->left,level-1);
    int right = width(root->right,level+1);

    maxi = max(maxi,level);
    mini = min(mini,level);

    return maxi-mini+1;    
}

int main()
{
    // Creating the root
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->right= new Node(8);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);

    // Function call
    //allTraversal(root);
    int ans = width(root,0);
    cout<<ans<<endl;

    return 0;
}
