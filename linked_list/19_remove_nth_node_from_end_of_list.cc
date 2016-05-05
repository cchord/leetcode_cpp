//
// Created by Neptune on 5/5/16.
//

/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 *      Given linked list: 1->2->3->4->5, and n = 2.
 *      After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 * Note:
 *      Given n will always be valid.
 *      Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) return nullptr;

        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *curr = dummyHead, *prev = nullptr, *toDel = dummyHead;
        int i = 1;

        while (curr) {
            if (i++ > n) {
                prev = toDel;
                toDel = toDel->next;
            }

            curr = curr->next;
        }

        prev->next = toDel->next;
        delete toDel;
        return dummyHead->next;
    }
};

int main() {
    ListNode *l = new ListNode(1);
    //l->next = new ListNode(2);
    //l->next->next = new ListNode(3);
    //l->next->next->next = new ListNode(4);
    //l->next->next->next->next = new ListNode(5);
    l = Solution().removeNthFromEnd(l, 1);

    for (auto p = l; p; p = p->next)
        cout << p->val << " ";

    cout << endl;
    return 0;
}
