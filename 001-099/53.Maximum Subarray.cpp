class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int cur = 0;
        for (auto n : nums) {
            if (cur > 0) {
                cur += n;
            } else {
                cur = n;
            }
            if (cur > ret) ret = cur;
        }
        return ret;
    }
};
