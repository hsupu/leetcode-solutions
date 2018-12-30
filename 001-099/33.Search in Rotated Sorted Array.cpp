class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return -1;
        }
        
        int l = 0, r = size;
        int lmin = nums[0], rmax = nums[size - 1];
        int m, mv;
        while (l < r) {
            m = (l + r) / 2;
            mv = nums[m];
            if (mv == target) {
                return m;
            }
            
            if (mv < target) {
                // go greater
                if (mv > rmax || target <= rmax) {
                    // m in l and go l.greater
                    // m in r and go r.greater
                    l = m + 1;
                } else {
                    // m in r and go l
                    r = m;
                }
            } else {
                // mv > target, go lesser
                if (mv < lmin || target >= lmin) {
                    // m in r and go r.lesser
                    // m in l and go l.lesser
                    r = m;
                } else {
                    // m in l and go r
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};
