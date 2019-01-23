# Two Sum

Question: Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

How would you first solve this problem? 

Easiest way to solve the problem is with an example

The dictionary brings the time complexity from O(n^2) to O(n). O(n) in essence means we only need to pass through the value in each list once. We're able to solve the problem doing this by storing the value to be retrieved later. In line 24 we check if the value was stored and if it was then we have a total summation.

