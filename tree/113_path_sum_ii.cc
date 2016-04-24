//
// Created by Neptune on 4/24/16.
//

/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 */
#include <vector>
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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> vec;
        pathSum(root, res, vec, sum);
        return res;
    }

    void pathSum(TreeNode *root, vector<vector<int>> &res, vector<int> &vec, int sum) {
        if (!root)
            return;

        if (!root->left && !root->right)
            if (sum == root->val) {
                vec.push_back(root->val);
                res.push_back(vec);
                vec.pop_back();
                return;
            }

        vec.push_back(root->val);
        pathSum(root->left, res, vec, sum - root->val);
        pathSum(root->right, res, vec, sum - root->val);
        vec.pop_back();
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    auto res = Solution().pathSum(root, 5);

    for (auto &vec : res) {
        for (auto n : vec)
            cout <<  n << " ";

        cout << endl;
    }

    return 0;
}
