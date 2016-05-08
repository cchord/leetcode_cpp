//
// Created by Neptune on 5/8/16.
//

/*
 * Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares
 * the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes
 * turned into left leaf nodes. Return the new root.
 *
 * For example:
 * Given a binary tree {1,2,3,4,5},
 *      1
 *     / \
 *    2   3
 *   / \
 *  4   5
 * return the root of the binary tree [4,5,2,#,#,3,1].
 *      4
 *     / \
 *    5   2
 *   / \
 *  3   1
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

class Solution {
  public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if (!root || (!root->left && !root->right))
            return root;

        auto newHead = upsideDownBinaryTree(root->left);
        auto rightMost = newHead;

        while (rightMost->right)
            rightMost = rightMost->right;

        rightMost->left = root->right;
        root->left = root->right = nullptr;
        rightMost->right = root;
        return newHead;
    }
};

int main() {
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);
    t->left->left = new TreeNode(4);
    t->left->right = new TreeNode(5);
    auto res = Solution().upsideDownBinaryTree(t);
    return 0;
}
