class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            if (nums[left] == val) {
                // Swap the target with the element at the right pointer
                nums[left] = nums[right];
                right--; // Shrink the valid bounds from the right
            } else {
                left++; // Move forward if the current element is valid
            }
        }
        return left; 
    }
};
