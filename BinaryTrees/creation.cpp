#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node() : data(0), right(nullptr), left(nullptr) {};
    Node(int x) : data(x), right(nullptr), left(nullptr) {};
    Node(int x, Node* left, Node* right) : data(x), right(right), left(left) {};
};

void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    Node* root = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3));
    cout << "Inorder traversal of the BST: ";
    inorder(root);

    return 0;
}

                1
             /   \
           2       3
         /   \
        4     5
    