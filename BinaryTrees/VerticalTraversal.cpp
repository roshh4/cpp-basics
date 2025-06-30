#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> qu;
    qu.push({root, {0, 0}});
    while (!qu.empty()) {
        auto p = qu.front(); qu.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->val);
        if (node->left) qu.push({node->left, {x - 1, y + 1}});
        if (node->right) qu.push({node->right, {x + 1, y + 1}});
    }
    vector<vector<int>> res;
    for (auto p : nodes) {
        vector<int> ver;
        for (auto q : p.second) {
            ver.insert(ver.end(), q.second.begin(), q.second.end());
        }
        res.push_back(ver);
    }
    return res;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> result = verticalTraversal(root);
    for (auto v : result) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }
    return 0;
}