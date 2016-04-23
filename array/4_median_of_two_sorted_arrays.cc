//
// Created by Neptune on 4/23/16.
//

/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
            int m = nums1.size(), n = nums2.size(), k = (m + n) / 2;
            int m1 = findKthElement(nums1, 0, m, nums2, 0, n, k + 1);

            if ((m + n) % 2 == 0) {
                int m2 = findKthElement(nums1, 0, m, nums2, 0, n, k);
                return (m1 + m2) / 2.0;
            }

            return m1;
        }

        int findKthElement(vector<int> &nums1, int s1, int e1, vector<int> &nums2, int s2, int e2, int k) {
            int m = e1 - s1, n = e2 - s2;

            if (m > n)
                return findKthElement(nums2, s2, e2, nums1, s1, e1, k); // let nums1 be the shorter one

            if (m == 0)
                return nums2[s2 + k - 1];

            if (k == 1)
                return min(nums1[s1], nums2[s2]);

            int pivot1 = min(m, k / 2);
            int pivot2 = k - pivot1;

            if (nums1[s1 + pivot1 - 1] == nums2[s2 + pivot2 - 1])
                return nums1[pivot1 - 1];
            else if (nums1[s1 + pivot1 - 1] < nums2[s2 + pivot2 - 1])
                return findKthElement(nums1, s1 + pivot1, e1, nums2, s2, s2 + pivot2, k - pivot1);
            else
                return findKthElement(nums1, s1, s1 + pivot1, nums2, s2 + pivot2, e2, k - pivot2);
        }
};

int main() {
    //vector<int> n1{1, 3, 4, 5, 10};
    //vector<int> n2{6, 7, 8, 9};
    vector<int> n1{1, 2};
    vector<int> n2{1, 2};
    cout << Solution().findMedianSortedArrays(n1, n2) << endl;
}
