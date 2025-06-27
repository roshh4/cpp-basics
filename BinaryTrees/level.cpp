#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* Left, TreeNode* Right): data(x), left(Left), right(Right) {}
};

void levelOrder(TreeNode* node){
    queue<TreeNode*> q;
    q.push(node);
    while(!q.empty())
    {
        node = q.front();
        if(node->left)
        {
            q.push(node->left);
        }
        if(node->right)
        {
            q.push(node->right);
        }
        cout << node->data << " ";
        q.pop();
    }
}

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    levelOrder(root);
}