class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // left ko aage badhao jab tak alphanumeric character na mile
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // right ko peeche laao jab tak alphanumeric character na mile
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};