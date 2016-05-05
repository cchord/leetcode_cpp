//
// Created by Neptune on 5/5/16.
//

/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

class Solution {
  public:
    #if 0
    // 1. DC
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists, int start, int end) {
        if (start == end) return lists[start];

        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        return merge2Lists(mergeKLists(lists, start, mid), mergeKLists(lists, mid + 1, end));
    }

    ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;

        if (!l2) return l1;

        if (l1->val > l2->val) {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        } else {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        }
    }
    #else
    struct comp {
        bool operator()(ListNode *l1, ListNode *l2) {
            return l1->val > l2->val;
        }
    };
    // priority_queue
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int size = lists.size();

        if (size == 0) return nullptr;

        priority_queue<ListNode *, vector<ListNode *>, comp> pq;

        for (auto l : lists)
            if (l)
                pq.push(l);

        ListNode *dummy = new ListNode(0), *curr = dummy;

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            curr->next = node;
            curr = node;

            if (node->next)
                pq.push(node->next);
        }

        return dummy->next;
    }
    #endif
};

int main() {
    vector<ListNode *> lists(4, nullptr);
    lists[0] = new ListNode(3);
    lists[1] = new ListNode(2);
    lists[2] = new ListNode(1);
    lists[3] = new ListNode(10);
    lists[3]->next = new ListNode(16);
    auto res = Solution().mergeKLists(lists);

    for (auto p = res; p; p = p->next)
        cout << p->val << " ";

    return 0;
}
