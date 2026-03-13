class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < (int)numbers.size() - 1; i++) {
            int complement = target - numbers[i];
            int lo = i + 1, hi = (int)numbers.size() - 1;
            
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (numbers[mid] == complement)
                    return {i + 1, mid + 1};  // 1-indexed
                else if (numbers[mid] < complement)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return {};  // guaranteed to have a solution
    }
};