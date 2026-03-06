class Solution {
public:
    int removeElement(vector<int>& nums, int value) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            if (nums[left] == value) {
                // unwanted element, replace with last element
                nums[left] = nums[right];
                right--;
            } else {
                // valid element, move ahead
                left++;
            }
        }

        // right + 1 is the count of valid elements
        return right + 1;
    }
};