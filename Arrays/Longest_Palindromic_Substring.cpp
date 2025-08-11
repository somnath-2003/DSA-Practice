//LeetCode Problem:5
//Longest Palindromic Substring
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1;  // At least one character is a palindrome

        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome: expand around center i
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }

            // Even length palindrome: expand around center i, i+1
            left = i; right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        }

        return s.substr(start, maxLen);
    }
};
