//
// Created by Neptune on 5/2/16.
//

/*
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * For example,
 *      Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 * Note:
 *      You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 *      Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;


class Solution {
    struct comp {
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        }
    };

  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

        for (auto &n : nums)
            map[n]++;

        for (auto &pair : map) {
            pq.emplace(pair.first, pair.second);

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> res;

        for (int i = 0; i < k; ++i) {
            auto pair = pq.top();
            pq.pop();
            res.push_back(pair.first);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<int> v{1, 1, 1, 2, 2, 3};
    auto res = Solution().topKFrequent(v, 2);

    for (auto n : res)
        cout << n << " ";

    cout << endl;
    return 0;
}
