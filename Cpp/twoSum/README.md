# Two Sum

Question: Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

For loop or two for loops (to be or not to be... super cheesy)

When I first tried doing this problem for the first time, I thought it was obvious. Naive as I was, I implemented two for loops to brute force every possible case and check if the sum matched. I remember feeling frustrated and crying out to my brother about why my program kept timing out.

It was that day I learned about the usefulness of the dictionary.

The dictionary brings the time complexity from O(n^2) to O(n). O(n) in essence means we only need to pass through the value in each list once. We're able to solve the problem doing this by storing the value to be retrieved later. In line 24 we check if the value was stored and if it was then we have a total summation.

