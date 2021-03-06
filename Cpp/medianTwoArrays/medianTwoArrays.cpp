//URL:https://leetcode.com/problems/median-of-two-sorted-arrays/
/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
*/

#include <limits>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m < n) return median(m, n, nums1, nums2);
        else return median(n, m, nums2, nums1);
    }
    
    double median(int m, int n, vector<int>& nums1, vector<int>& nums2) {
        // m <= n, so we start by looking at the partition of nums1
        int start = 0;
        int end = m;
        while (start <= end) {
            // Find the partitions of nums1 and nums2 
            int partNums1 = (start+end)/2;
            int partNums2 = ((m+n+1)/2)-partNums1;
            // Find the max value of nums1 on the left and min value on the right
            // If the partition is on the edge where there are no numbers on one side then use max/min value
            int maxLeft1 = (partNums1 == 0) ? std::numeric_limits<int>::min() : nums1[partNums1-1];
            int minRight1 = (partNums1 == m) ? std::numeric_limits<int>::max() : nums1[partNums1];
            // Do the same for nums2
            int maxLeft2 = (partNums2 == 0) ? std::numeric_limits<int>::min() : nums2[partNums2-1];
            int minRight2 = (partNums2 == n) ? std::numeric_limits<int>::max() : nums2[partNums2];
            // Now make checks, our goal is to get maxLeft1 <= minRight2 and maxLeft2 <= minRight1
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Two cases: if the merged array is even or odd
                if ((m+n)%2==0) {
                    return ((max(maxLeft1, maxLeft2) + min(minRight1, minRight2))/2.0);
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            // If maxLeft1 > minRight2 then we need to move the partition to the left. Doing it like this makes it go in log time, because it's a binary search
            } else if (maxLeft1 > minRight2) {
                end = partNums1-1;
            } else {
                // If maxLeft2 > minRight1 then we move the partition to the right by cutting it in half again
                start = partNums1+1;
            }
        }
        // Should never be able to reach here unless the lists are unsorted
        return 2.0;
    }
};
