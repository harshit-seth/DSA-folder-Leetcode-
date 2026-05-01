class Solution {
public:
    // Merge two sorted halves
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Temporary arrays
        vector<int> L(n1), R(n2);

        // Copy data into temp arrays
        for (int i = 0; i < n1; i++) L[i] = nums[left + i];
        for (int j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];

        int i = 0, j = 0, k = left;

        // Compare and merge back
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) nums[k++] = L[i++];
            else nums[k++] = R[j++];
        }

        // Copy remaining elements
        while (i < n1) nums[k++] = L[i++];
        while (j < n2) nums[k++] = R[j++];
    }

    // Recursive merge sort
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {                          // Base case: single element
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);              // Sort left half
            mergeSort(nums, mid + 1, right);         // Sort right half
            merge(nums, left, mid, right);           // Merge both halves
        }
    }

    // Main function called by LeetCode
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};