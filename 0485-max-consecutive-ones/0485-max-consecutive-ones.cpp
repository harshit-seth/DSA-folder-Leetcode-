class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_streak = 0;
        int current_streak = 0;
        
        // Linear search: scanning the array from index 0 to n-1
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                current_streak++; // Increment streak if 1 is found
                if (current_streak > max_streak) {
                    max_streak = current_streak; // Update max streak
                }
            } else {
                current_streak = 0; // Reset streak if 0 is found
            }
        }
        
        return max_streak;
    }
};
