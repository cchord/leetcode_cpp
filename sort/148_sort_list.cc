//
// Created by Neptune on 4/26/16.
//

/*
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

#include <iostream>

using namespace std;

struct ListNode {
    int label;
    ListNode *next;
    ListNode(int x) : label(x), next(nullptr) { }
};

class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *slow = head, *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto head2 = slow->next;
        slow->next = nullptr;
        return merge2Lists(sortList(head), sortList(head2));
    }

    auto merge2Lists(ListNode *l1, ListNode *l2) -> ListNode * {
        if (!l1) return l2;

        if (!l2) return l1;

        if (l1->label > l2->label) {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        } else {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        }
    }
};

int main() {
    auto l = new ListNode(9);
    l->next = new ListNode(8);
    l->next->next = new ListNode(7);
    l->next->next->next = new ListNode(6);
    l->next->next->next->next = new ListNode(5);
    l->next->next->next->next->next = new ListNode(4);
    l->next->next->next->next->next->next = new ListNode(3);
    l = Solution().sortList(l);

    for (auto it = l; it != nullptr; it = it->next)
        cout << it->label << " ";

    cout << endl;
    return 0;
}
