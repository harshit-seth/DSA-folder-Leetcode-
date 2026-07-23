class Solution {
public:
    int countBits(int n) {
        int bits = 0;
        while (n > 0) {
            bits++;
            n >>= 1;
        }
        return bits;
    }

    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        return pow(2, countBits(n));
    }
};