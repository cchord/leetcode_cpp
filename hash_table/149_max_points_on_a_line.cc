//
// Created by Neptune on 5/2/16.
//

/*
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) { }
};

class Solution {
  public:
    int maxPoints(vector <Point> &points) {
        int num = points.size();

        if (num <= 1) return num;

        int maxVal = 0;

        for (int i = 0; i < num; ++i) {
            unordered_map<double, int> map;
            int dupCount = 0;
            int localMax = 0;

            for (int j = i + 1; j < num; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    dupCount++;
                    continue;
                }

                double slope = 0;

                if (points[i].x == points[j].x)
                    slope = numeric_limits<double>::max();
                else
                    slope = (double)(points[i].y - points[j].y) / (double)(points[i].x - points[j].x);

                if (map.find(slope) == map.end())
                    map[slope] = 1;

                localMax = max(++map[slope], localMax);
            }

            if (map.size() == 0)
                localMax++;

            localMax += dupCount;
            maxVal = max(maxVal, localMax);
        }

        return maxVal;
    }
};

int main() {
    vector<Point> v{
        {0, 0}, {1, 1}, {2, 2}, {3, 3},
        {0, 1}, {0, 2},
        {0, 3}, {1, 3}, {2, 3},
        {0, 0}, {0, 0}
    };
    cout << Solution().maxPoints(v) << endl;
    return 0;
}
