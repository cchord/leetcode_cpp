//
// Created by Neptune on 5/2/16.
//

/*
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 *      Could you do it in O(n) time and O(1) space?
 */
#include <iostream>

struct ListNode {
    int label;
    ListNode *next;
    ListNode(int x) : label(x), next(nullptr) { }
};

using namespace std;

class Solution {
  public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto head2 = slow->next;
        slow->next = nullptr;
        // reverse head2
        ListNode *prev = nullptr;

        while (head2) {
            auto next = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = next;
        }

        // compare
        while (prev && head) {
            if (prev->label != head->label)
                return false;

            prev = prev->next;
            head = head->next;
        }

        return true;
    }
};

int main() {
    auto l = new ListNode(2);
    l->next = new ListNode(1);
    l->next->next = new ListNode(1);
    cout << Solution().isPalindrome(l) << endl;
    return 0;
}
