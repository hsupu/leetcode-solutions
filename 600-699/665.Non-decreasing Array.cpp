class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int last = 0;
        bool modified = false;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                if (modified) return false;
                
                if (last < nums[i]) {
                    // we can modify n-1 to fix it
                    // nums[n-1] = last;
                } else {
                    // or we try to modify n
                    nums[i] = nums[i - 1];
                }
                modified = true;
            }
            last = nums[i - 1];
        }
        return true;
    }
};