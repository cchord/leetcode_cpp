//
// Created by Neptune on 4/23/16.
//

/*
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 * For example,
 *      Given n = 3, your program should return all 5 unique BST's shown below.
 */
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode *>();

        vector<int> vec(n, 0);

        for (int i = 0; i < n; ++i)
            vec[i] = i + 1;

        return genTrees(vec, 0, static_cast<int>(vec.size()));
    }

    vector<TreeNode *> genTrees(vector<int> &nums, int s, int e) {
        if (s == e)
            return vector<TreeNode *>({nullptr});
        vector<TreeNode *> trees;

        for (int i = s; i < e; ++i) {
            auto l = genTrees(nums, s, i);
            auto r = genTrees(nums, i + 1, e);

            for (auto lnode : l)
                for (auto rnode : r) {
                    TreeNode *tree = new TreeNode(nums[i]);
                    tree->left = lnode;
                    tree->right = rnode;
                    trees.push_back(tree);
                }
        }

        return trees;
    }

    vector<int> traversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;

        while (root || !s.empty()) {
            while (root) {
                res.push_back(root->val);
                s.push(root);
                root = root->left;
            }

            auto node = s.top();
            s.pop();
            root = node->right;
        }

        return res;
    }
};

int main() {
    Solution s;
    auto res = s.generateTrees(3);

    for (auto tree : res) {
        auto res = s.traversal(tree);

        for (auto n : res)
            cout << n << " ";

        cout << endl;
    }

    return 0;
}
