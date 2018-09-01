class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int min3 = nums[0] + nums[1] + nums[2] - target;
        if (min3 >= 0) return min3 + target;
        
        int size = nums.size();
        int max3 = nums[size-1] + nums[size-2] + nums[size-3] - target;
        if (max3 <= 0) return max3 + target;
        
        int bestdiff, bestabs;
        bestdiff = (abs(min3) < abs(max3)) ? min3 : max3;
        bestabs = abs(bestdiff);
        
        int i, j, k, imax, diff, tmp;
        for (i = 0, imax = size-3; i <= imax; ++i) {
            tmp = nums[i] - target;
            j = i+1;
            k = size-1;
            while (j < k) {
                diff = tmp + nums[j] + nums[k];
                if (diff == 0) {
                    return target;
                } else {
                    if (abs(diff) < bestabs) {
                        bestdiff = diff;
                        bestabs = abs(diff);
                    }
                    if (diff > 0) {
                        --k;
                    } else {
                        ++j;
                    }
                }
            }
        }
        return bestdiff + target;
    }
};