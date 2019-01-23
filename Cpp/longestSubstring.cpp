// URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/
/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // We have a 256-long vector for all ASCII possibilities. -1 represents the character is not used. We set -1 to start to be in accordance with the -1 in the vector
        std::vector<int> indices(256, -1);
        int maxLen = 0;
        int start = -1;
        // Loop
        for (int i=0; i<s.length(); i++) {
            // Check for repeated characters by finding the index using the ASCII value. If the index is larger than
            // start then we need to move it
            if (indices[s[i]] > start) {
                start = indices[s[i]];
            }
            // Set the index of the ASCII value to the index
            indices[s[i]] = i;
            // Check if the max length needs to be updated
            // i-start works for start = -1 because the way indexing works. if the word was "straw", maxLen = 4-(-1)=5
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};
