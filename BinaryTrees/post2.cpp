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

void postorder(TreeNode* root)
{
    stack <TreeNode*> s1, s2;
    s1.push(root);
    while(!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if(root->left)
        {
            s1.push(root->left);
        }
        if(root->right)
        {
            s1.push(root->right);
        }
    }
    while(!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main()
{
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    postorder(root);
}