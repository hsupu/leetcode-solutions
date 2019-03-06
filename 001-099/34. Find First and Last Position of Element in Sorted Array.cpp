typedef int (*comparator)(vector<int>&, int, int);

int find_v(vector<int>& nums, int i, int target) {
    int v = nums[i];
    if (v == target) return 0;
    if (v < target) return -1;
    else return 1;
}

int find_l(vector<int>& nums, int i, int target) {
    if (nums[i] == target) {
        if (i == 0 || nums[i-1] < target) return 0;
        else return 1;
    } else {
        return -1;
    }
}

int find_r(vector<int>& nums, int i, int target) {
    if (nums[i] == target) {
        if (i == nums.size()-1 || nums[i+1] > target) return 0;
        else return -1;
    } else {
        return 1;
    }
}

int bsearch(vector<int>& nums, int l, int r, int target, comparator cmp) {
    while (l < r) {
        int m = (l + r) / 2;
        int t = cmp(nums, m, target);
        if (t == 0) return m;
        if (t < 0) l = m + 1;
        else r = m;
    }
    return -1;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        int size = nums.size();
        int p = bsearch(nums, 0, size, target, find_v);
        if (p == -1) {
            ret.push_back(-1);
            ret.push_back(-1);
        } else {
            int l = bsearch(nums, 0, p + 1, target, find_l);
            int r = bsearch(nums, p, size, target, find_r);
            ret.push_back(l);
            ret.push_back(r);
        }
        return ret;
    }
};
