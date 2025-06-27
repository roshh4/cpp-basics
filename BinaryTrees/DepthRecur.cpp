#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* Left, TreeNode* Right): data(x), left(Left), right(Right) {}
};

int maxDepth(TreeNode* node){
    if(!node) return 0;
    int lh = maxDepth(node->left);
    int rh = maxDepth(node->right);
    return 1 + max(lh, rh);
}

int main()
{
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(8, new TreeNode(2), nullptr), nullptr), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    int x = maxDepth(root);
    cout << "depth is " << x;
}