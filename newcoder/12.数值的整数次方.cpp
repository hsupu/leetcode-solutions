class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) return 1;
        double ret = 1;
        if (exponent > 0) {
            while (exponent) {
                ret *= base;
                exponent--;
            }
        } else {
            while (exponent) {
                ret /= base;
                exponent++;
            }
        }
        return ret;
    }
};
