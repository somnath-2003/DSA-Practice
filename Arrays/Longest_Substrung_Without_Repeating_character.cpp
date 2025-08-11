// LeetCode Problem: 3. Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty: Medium
// Language: C++
// Approach 1: Brute Force (O(n^3)) — Your implementation
// Approach 2: Sliding Window with HashSet (O(n)) — Optimized version

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Your Brute Force Implementation
    int lengthOfLongestSubstring(string s) {
        int count1 = 0, count2 = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                bool flag = false;
                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
                count1++;
                if (count1 > count2) {
                    count2 = count1;
                }
            }
            count1 = 0;
        }
        return count2;
    }

    // Optimized Sliding Window Implementation
    int lengthOfLongestSubstringOptimized(string s) {
        unordered_set<char> chars;
        int left = 0, right = 0, maxLen = 0;

        while (right < s.length()) {
            if (chars.find(s[right]) == chars.end()) {
                chars.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                chars.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};
