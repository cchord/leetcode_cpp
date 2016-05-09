//
// Created by Neptune on 5/9/16.
//

/*
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 *      You may only use constant extra space.
 *
 *      For example,
 *      Given the following binary tree,
 *             1
 *           /  \
 *          2    3
 *         / \    \
 *        4   5    7
 *
 *  After calling your function, the tree should look like:
 *
 *             1 -> NULL
 *           /  \
 *          2 -> 3 -> NULL
 *         / \    \
 *        4-> 5 -> 7 -> NULL
 */

#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) { }
};

class Solution {
  public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *list_iter = root;

        while (list_iter) {
            TreeLinkNode *prev = nullptr, *nextListHead = nullptr;

            while (list_iter) {
                if (list_iter->left) {
                    if (!nextListHead) nextListHead = list_iter->left;

                    if (prev) prev->next = list_iter->left;

                    if (list_iter->right) {
                        list_iter->left->next = list_iter->right;
                        prev = list_iter->right;
                    } else
                        prev = list_iter->left;
                } else {
                    if (list_iter->right) {
                        if (!nextListHead) nextListHead = list_iter->right;

                        if (prev) prev->next = list_iter->right;

                        prev = list_iter->right;
                    }
                }

                list_iter = list_iter->next;
            }

            list_iter = nextListHead;
        }
    }
};

int main() {
    TreeLinkNode *t = new TreeLinkNode(1);
    t->left = new TreeLinkNode(2);
    t->right = new TreeLinkNode(3);
    t->left->left = new TreeLinkNode(4);
    t->right->right = new TreeLinkNode(5);
    Solution().connect(t);
    return 0;
}
