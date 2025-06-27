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
    queue<TreeNode*> q;
    int x = 0;
    q.push(node);
    while(!q.empty())
    {
        x++;
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return x;
}

int main()
{
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(8), nullptr), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    int x = maxDepth(root);
    cout << "depth is " << x;
}