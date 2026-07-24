class Solution {
public:
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    std::string longestPalindrome(std::string s) {
        if (s.length() < 1) return "";
        if (s.length() == 1) return s;

        int start = 0, maxLength = 1;
        for (int i = 0; i < s.length(); ++i) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int cur = std::max(len1, len2);
            if (cur > maxLength) {
                maxLength = cur;
                start = i - (cur - 1) / 2;
            }
        }
        return s.substr(start, maxLength);
    }
};