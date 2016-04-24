//
// Created by Neptune on 4/24/16.
//

/*
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }

    TreeNode *sortedArrayToBST(vector<int> &nums, int s, int e) {
        if (s == e)
            return nullptr;

        int mid = s + (e - s) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, s, mid);
        root->right = sortedArrayToBST(nums, mid + 1, e);
        return root;
    }
};

void prtInorder(TreeNode *root) {
    if (root) {
        prtInorder(root->left);
        cout << root->val << " ";
        prtInorder(root->right);
    }
}

void prtPreorder(TreeNode *root) {
    if (root) {
        cout << root->val << " ";
        prtPreorder(root->left);
        prtPreorder(root->right);
    }
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    TreeNode *tree = Solution().sortedArrayToBST(v);
    prtPreorder(tree);
    cout << endl;
    prtInorder(tree);
    return 0;
}

