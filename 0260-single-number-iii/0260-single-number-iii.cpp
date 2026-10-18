class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;

        for (int num : nums) {
            x ^= num;
        }

        long long bit = (long long)x & -(long long)x;

        int a = 0, b = 0;

        for (int num : nums) {
            if ((num & bit) != 0)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};