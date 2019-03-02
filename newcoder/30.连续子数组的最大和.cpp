class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int cur = array[0];
        int maxval = cur;
        int size = array.size();
        for (int i = 1; i < size; ++i) {
            if (cur < 0) {
                cur = array[i];
            } else {
                cur += array[i];
            }
            if (cur > maxval) maxval = cur;
        }
        return maxval;
    }
};
