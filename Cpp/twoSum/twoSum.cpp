// https://leetcode.com/problems/two-sum/

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_ind;
        vector<int> ret;
        for (int i=0; i<nums.size(); i++) {
            // If the dictionary contains the value, target-nums[i]. Then value + nums[i] = target
            int value = target-nums[i];
            if (num_ind.find(value) != num_ind.end()) {
                ret.push_back(num_ind[value]);
                ret.push_back(i);
                return ret;
            }
            num_ind[nums[i]] = i;
        }
        // Should never reach here
        return ret;
    }
    
};