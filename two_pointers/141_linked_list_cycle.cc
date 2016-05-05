//
// Created by Neptune on 5/2/16.
//

/*
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 *      Can you solve it without using extra space?
 */

struct ListNode {
    int label;
    ListNode *next;
    ListNode(int x) : label(x), next(nullptr) { }
};

class Solution {
  public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;

        ListNode *slow = head, *fast = head->next;

        while (fast && fast->next) {
            if (slow->label == fast->label)
                return true;

            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};

int main() {
    return 0;
}
