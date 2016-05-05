//
// Created by Neptune on 5/5/16.
//

/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together
 * the nodes of the first two lists.
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;

        if (!l2) return l1;

        if (l1->val > l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        } else {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
};

int main() {
    auto l1 = new ListNode(1);
    l1->next = new ListNode(10);
    auto l2 = new ListNode(12);
    auto l = Solution().mergeTwoLists(l1, l2);

    for (auto p = l; p; p = p->next)
        cout << p->val << " ";

    return 0;
}
