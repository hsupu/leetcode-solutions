class Solution {
public:
    
    void swap(vector<int>& nums, int x, int y) {
        int t = nums[x];
        nums[x] = nums[y];
        nums[y] = t;
    }
    
    void foo(vector<vector<int>>& ret, vector<int> nums, int last, int step) {
        if (step == last) {
            ret.push_back(nums);
            return;
        }
        foo(ret, nums, last, step+1);
        for (int i = step + 1; i <= last; ++i) {
            swap(nums, step, i);
            foo(ret, nums, last, step+1);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        foo(ret, nums, nums.size()-1, 0);
        return ret;
    }
};
