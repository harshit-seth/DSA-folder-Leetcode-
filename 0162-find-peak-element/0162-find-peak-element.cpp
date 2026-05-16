class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // Peak is on the left side (including mid)
                end = mid;
            } else {
                // Peak is on the right side
                start = mid + 1;
            }
        }
        return start;
    }
};