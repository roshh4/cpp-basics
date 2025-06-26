#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* Right): val(x), left(left), right(Right) {}
};

void inorder(TreeNode* root)
{
    stack <TreeNode*> stk;
    
    while(root || !stk.empty())
    {
        while(root)
        {
            stk.push(root);
            root = root->left;
        }

        root = stk.top();
        stk.pop();
        cout << root->val << " ";
        root = root->right;
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left =new TreeNode(4);
    root->left->right = new TreeNode(5);

    inorder(root);
}