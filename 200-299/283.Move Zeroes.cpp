class Solution {
public:
    int getNonZero(vector<int>& nums, int start) {
        for (int j = start; j < nums.size(); ++j) {
            if (nums[j] != 0) return j;
        }
        return -1;
    }
    
    void moveZeroes(vector<int>& nums) {
        int j;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                j = getNonZero(nums, i + 1);
                if (j == -1) {
                    break;
                } else {
                    nums[i] ^= nums[j] ^= nums[i] ^= nums[j];
                }
            }
        }
    }
};
