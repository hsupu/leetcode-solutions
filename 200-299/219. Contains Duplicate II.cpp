class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mmap;
        for (int i = 0; i < nums.size(); ++i) {
            if (mmap.find(nums[i]) != mmap.end() && (i - mmap[nums[i]]) <= k)
                return true;
            else
                mmap[nums[i]] = i;
        }
        return false;
    }
};
