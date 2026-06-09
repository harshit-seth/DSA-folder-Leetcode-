class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            
            // Ensure mid is even for consistent pairing logic
            if (mid % 2 == 1) {
                mid--;
            }
            
            // Check if mid and mid+1 form a pair
            if (nums[mid] == nums[mid + 1]) {
                // Pair is intact, single element is on the right
                start = mid + 2;
            } else {
                // Pair is broken, single element is on the left (or at mid)
                end = mid;
            }
        }
        
        return nums[start];
    }
};