//
// Created by Neptune on 5/2/16.
//

/*
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Note: Do not modify the linked list.
 *
 * Follow up:
 *      Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode *slow = head->next, *fast = head->next->next;
        bool hasCycle = false;

        while (fast && fast->next) {
            if (slow == fast) {
                hasCycle = true;
                break;
            }

            slow = slow->next, fast = fast->next->next;
        }

        if (!hasCycle)
            return nullptr;

        slow = head;

        while (slow) {
            if (slow == fast)
                return slow;

            slow = slow->next, fast = fast->next;
        }

        return nullptr;
    }
};

int main() {
    auto l = new ListNode(1);
    l->next = new ListNode(2);
    //l->next->next = new ListNode(3);
    //l->next->next = l;
    auto node = Solution().detectCycle(l);
    cout << (node ? to_string(node->label) : string("no cycle detected")) << endl;
    return 0;
}
