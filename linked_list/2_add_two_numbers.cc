//
// Created by Neptune on 5/5/16.
//

/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and
 * each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addTwoNumbers(l1, l2, 0);
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
        if (!l1 && !l2)
            return carry ? new ListNode(carry) : nullptr;

        int operand1 = l1 ? l1->val : 0;
        int operand2 = l2 ? l2->val : 0;
        int sum = operand1 + operand2 + carry;
        ListNode *currNode = new ListNode(sum % 10);
        currNode->next = addTwoNumbers(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, sum / 10);
        return currNode;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(2);
    l2->next->next = new ListNode(3);
    l2->next->next->next = new ListNode(8);
    l2->next->next->next->next = new ListNode(9);
    auto res = Solution().addTwoNumbers(l1, l2);

    for (auto p = res; p ; p = p->next)
        cout << p->val << " ";

    cout << endl;
    return 0;
}
