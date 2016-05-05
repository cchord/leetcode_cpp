//
// Created by Neptune on 5/5/16.
//

/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 *
 *      Given 1->1->2, return 1->2.
 *      Given 1->1->2->3->3, return 1->2->3.
 */

//using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        return nullptr;
    }
};

int main() {
    return 0;
}
