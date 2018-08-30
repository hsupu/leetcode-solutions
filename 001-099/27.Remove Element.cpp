class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int used = 0;
        int skip_head, skip_tail;
        skip_head = size;
        skip_tail = 0;
        int cur, tmp;
        bool skip;
        for (int i = 0; i < size; ++i) {
            skip = true;
            cur = nums[i];
            if (cur != val) {
                //printf("used=%d i=%d head=%d\n", used, i, skip_head);
                if (used < i) {
                    tmp = nums[skip_head];
                    nums[skip_head] = cur;
                    skip_head = tmp;
                } else {
                    skip = false;
                }
                ++used;
            }
            if (skip) {
                if (skip_tail <= skip_head) nums[skip_tail] = i;
                skip_tail = i;
                nums[skip_tail] = size;
                if (skip_head == size) skip_head = skip_tail;
            }
        }
        return used;
    }
};