class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: if the array is empty, there are no elements to process.
        if (nums.empty()) return 0;

        // 'i' is the slow pointer (Writer). 
        // It tracks the boundary of our unique elements. 
        // The first element is always unique, so we start 'i' at index 0.
        int i = 0;

        // 'j' is the fast pointer (Explorer). 
        // It scans through the rest of the array starting from index 1.
        for (int j = 1; j < nums.size(); j++) {
            
            // If the element at 'j' is different from our last known unique element at 'i'
            if (nums[j] != nums[i]) {
                
                // Step 1: Advance 'i' to the next available position
                i++;
                
                // Step 2: Copy the new unique element into the unique section
                nums[i] = nums[j];
            }
            // If nums[j] == nums[i], it's a duplicate, 
            // so we skip it by just letting the loop increment 'j'.
        }

        // Since 'i' is an index (0-based), the total number of unique elements 
        // will be the index 'i' plus 1.
        return i + 1;
    }
};