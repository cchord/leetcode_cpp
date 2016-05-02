//
// Created by Neptune on 5/2/16.
//

/*
 * A linked list is given such that each node contains an additional random pointer which could point to any node
 * in the list or null.
 *
 * Return a deep copy of the list.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) { }
};


class Solution {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;

        unordered_map<RandomListNode *, RandomListNode *> map;
        auto curr = head;
        RandomListNode *prev = nullptr;

        while (curr) {
            if (map.find(curr) == map.end())
                map[curr] = new RandomListNode(curr->label);

            if (curr->random) {
                if (map.find(curr->random) == map.end())
                    map[curr->random] = new RandomListNode(curr->random->label);

                map[curr]->random = map[curr->random];
            }

            if (prev)
                map[prev]->next = map[curr];

            prev = curr;
            curr = curr->next;
        }

        return map[head];
    }
};

int main() {
    return 0;
}
