class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Array ko sort kiya (O(N log N) time)
        return nums[nums.size() / 2];   // Middle element hi majority element hoga
    }
};

