//
// Created by Neptune on 4/24/16.
//
/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then
 * right to left for the next level and alternate between).
 */
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;

        if (!root) return res;

        stack<TreeNode *> s1, s2;
        s1.push(root);
        bool leftToRight = true;

        while (!s1.empty()) {
            vector<int> v;

            while (!s1.empty()) {
                auto node = s1.top();
                s1.pop();
                auto c1 = leftToRight ? node->left : node->right;
                auto c2 = leftToRight ? node->right : node->left;

                if (c1)
                    s2.push(c1);

                if (c2)
                    s2.push(c2);

                v.push_back(node->val);
            }

            res.push_back(v);
            leftToRight = !leftToRight;
            swap(s1, s2);
        }

        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto res = Solution().zigzagLevelOrder(root);

    for (auto &vec : res) {
        for (auto n : vec)
            cout << n << " ";

        cout << endl;
    }

    return 0;
}
