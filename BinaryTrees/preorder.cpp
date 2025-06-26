#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* Left, TreeNode* Right): data(x), left(Left), right(Right) {}
};

void preorder(TreeNode* root)
{
    if(root == nullptr)
    {
        return;
    }    
    stack <TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        cout << node->data << " ";
        if(node->right)
        {
            st.push(node->right);
        }
        if(node->left)
        {
            st.push(node->left);
        }
    }
}
int main()
{
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    preorder(root);
}