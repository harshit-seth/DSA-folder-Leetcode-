class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;

        for (char c : t) {
            if (i < s.length() && c == s[i]) {  // match character
                i++;
            }
        }

        return i == s.length();  // all chars of s matched?
    }
};