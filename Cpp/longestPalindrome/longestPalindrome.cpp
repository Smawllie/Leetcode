// URL: https://leetcode.com/problems/longest-palindromic-substring/
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
*/
class Solution {
public:
    // 
    string longestPalindrome(string s) {
        const int slen = s.size();
        if (slen <= 1) {
            return s;
        } else {
            for (int low=0; low < slen-1; low++) {
                // Because we want to check both odd and even we loop until the second to last element, not last element
                extendPalin(s, low, low); // Odd
                extendPalin(s, low, low+1); // Even
            }
            return s.substr(lowBound, maxLength);
        }
    }
    
    void extendPalin(string s, int low, int high) {
        while (low >= 0 && high<s.length() && s.at(low) == s.at(high)) {
            low--;
            high++;
        }
        // Now we have the longest palindrome starting in the middle index of low/high. We need to check if this
        // is the longest palindrome globally
        // Note however that low and high are actually one off because the last check didn't go through so we need to adjust
        if (maxLength < (high-low)-1) {
            lowBound = low+1;
            maxLength = (high-low)-1;
        }
    }
    
    
private:
    // Create private variables to hold the longest palindrome
    int lowBound=0, maxLength=0;
};
