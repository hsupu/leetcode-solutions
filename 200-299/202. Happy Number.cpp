class Solution {
public:
    bool isHappy(int n) {
        int old[100] = {0};
        int count = 0;
        int v = n;
        int t;
        while (1) {
            n = v;
            v = 0;
            while (n) {
                t = n % 10;
                v += t * t;
                n /= 10;
            }
            if (v == 1) return true;
            for (int i = 0; i < count; ++i) {
                if (v == old[i]) {
                    return false;
                }
            }
            old[count++] = v;
        }
    }
};
