//
// Created by Neptune on 5/12/16.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
  public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        // step 1 - store coords into a multimap
        multimap<int, int> coords;

        for (auto &bd : buildings) {
            coords.emplace(bd[0], bd[2]);
            coords.emplace(bd[1], -bd[2]);
        }

        // step 2 - draw skyline
        multiset<int> heights = {0};
        map<int, int> corners;

        for (auto &p : coords) {
            if (p.second > 0)
                heights.insert(p.second);
            else
                heights.erase(heights.find(-p.second));

            corners[p.first] = *heights.rbegin();
        }

        // step 3 - remove duplicates
        vector<pair<int, int>> results;
        unique_copy(corners.begin(), corners.end(), back_insert_iterator<vector<pair<int, int>>>(results),
        [](pair<int, int> l, pair<int, int> r) {
            return l.second == r.second;
        });
        return results;
    }
};

int main() {
    vector<vector<int>> buildings{ {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    auto res = Solution().getSkyline(buildings);

    for (auto p : res)
        cout << "{" << p.first << "," << p.second << "} ";

    cout << endl;
    return 0;
}
