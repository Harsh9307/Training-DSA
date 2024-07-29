#include <bits/stdc++.h>
using namespace std;

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

void allTraversal(Node* root)
{
    vector<int> preOrder, inOrder, postOrder;
    stack<pair<Node*, int>> st;
    if (root == NULL) return;

    Node* node = root;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // Preorder
        if (it.second == 1) {
            preOrder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        // Inorder
        else if (it.second == 2) {
            inOrder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        // Postorder
        else {
            postOrder.push_back(it.first->val);
        }
    }

    cout << "Preorder Traversal: ";
    for (int i = 0; i < preOrder.size(); i++) {
        cout << preOrder[i] << " ";
    }
    cout << "\n";

    cout << "Inorder Traversal: ";
    for (int i = 0; i < inOrder.size(); i++) {
        cout << inOrder[i] << " ";
    }
    cout << "\n";

    cout << "Postorder Traversal: ";
    for (int i = 0; i < postOrder.size(); i++) {
        cout << postOrder[i] << " ";
    }
    cout << "\n";
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
    root->right->right = new Node(7);

    // Function call
    allTraversal(root);

    return 0;
}
