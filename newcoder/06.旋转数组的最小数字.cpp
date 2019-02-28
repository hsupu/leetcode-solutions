class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) return 0;
        int a = 0, b = rotateArray.size();
        int m, v, minval = rotateArray[0];
        while (a < b) {
            m = (a + b) / 2;
            v = rotateArray[m];
            if (v >= rotateArray[0]) {
                a = m + 1;
            } else {
                minval = v;
                b = m;
            }
        }
        return minval;
    }
};
