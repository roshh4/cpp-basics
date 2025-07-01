#include<iostream>
#include<queue>
#include<map>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* Left, TreeNode* Right): data(x), left(Left), right(Right) {}
};

void rightView(TreeNode* node){
    queue <pair<TreeNode*, int>> q;
    if(!node) return;
    map <int, int> m;
    q.push({node, 0});
    while(!q.empty())
    {
        auto p = q.front();
        int x = p.second;
        q.pop();
        node = p.first;
        m[x] = node->data;
        if(node->left)
        {
            q.push({node->left, x+1});
        }
        if(node->right)
        {
            q.push({node->right, x+1});
        }
    }
    for(auto v : m)
    {
        cout << v.second << " ";
    }
}

int main(){
    TreeNode* node = new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, new TreeNode(5, nullptr, new TreeNode(6))), new TreeNode(10)), new TreeNode(3, new TreeNode(9), new TreeNode(11)));
    rightView(node);
}