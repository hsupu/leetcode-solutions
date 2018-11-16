class Solution {
public:

    void swapAll(vector<int>& nums, int l, int r) {
        int x;
        int i = l;
        int j = r;
        while (i < j) {
            x = nums[i];
            nums[i] = nums[j];
            nums[j] = x;
            i++;
            j--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i;
        int j;
        int x = nums[size-1];
        int y;
        for (i = size-2; i >= 0; --i) {
            y = nums[i];
            if (y < x) {
                for (j = size-1; j > i; --j) {
                    if (y < nums[j]) {
                        x = nums[j];
                        
                        nums[i] = x;
                        nums[j] = y;
                        break;
                    }
                }
                break;
            }
            x = y;
        }
        swapAll(nums, i+1, size-1);
    }
};