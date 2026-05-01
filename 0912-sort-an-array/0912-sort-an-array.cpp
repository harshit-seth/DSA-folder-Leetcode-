class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> L(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> R(nums.begin() + mid + 1, nums.begin() + right + 1);

        int i = 0, j = 0, k = left;

        while (i < L.size() && j < R.size()) {
            if (L[i] <= R[j]) nums[k++] = L[i++];
            else nums[k++] = R[j++];
        }

        while (i < L.size()) nums[k++] = L[i++];
        while (j < R.size()) nums[k++] = R[j++];
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};