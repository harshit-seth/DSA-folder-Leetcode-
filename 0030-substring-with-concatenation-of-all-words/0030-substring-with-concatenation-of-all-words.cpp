#include <string>
#include <vector>
#include <unordered_map>
#include <string_view>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int sLen = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (sLen < totalLen) return ans;

        // Build the frequency map of target words
        unordered_map<string_view, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }

        // Use string_view to avoid string copies/allocations during slicing
        string_view s_view(s);

        // Slide the window with 'wordLen' different offsets
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int count = 0;
            unordered_map<string_view, int> currentMap;

            for (int right = i; right + wordLen <= sLen; right += wordLen) {
                string_view word = s_view.substr(right, wordLen);

                if (wordMap.count(word)) {
                    currentMap[word]++;
                    count++;

                    // If a word is over-utilised, shrink the window from the left
                    while (currentMap[word] > wordMap[word]) {
                        string_view leftWord = s_view.substr(left, wordLen);
                        currentMap[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Valid match found
                    if (count == wordCount) {
                        ans.push_back(left);
                        // Slide left pointer forward to look for next matches
                        string_view leftWord = s_view.substr(left, wordLen);
                        currentMap[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    // Invalid word found: reset the window tracking
                    currentMap.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};
