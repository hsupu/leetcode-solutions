const int MINVAL = -2147483648;
const int MAXVAL = 2147483647;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 题目要求结果超出范围给极限值，然而只有这一种情况会超
        if (dividend == MINVAL && divisor == -1) return MAXVAL;

        int sign = (dividend < 0) ^ (divisor < 0);
        long long int a = dividend < 0 ? -(long long int)dividend : dividend;
        long long int b = divisor < 0 ? -(long long int)divisor : divisor;
        if (a < b) return 0;

        int c = 0;
        long long int l = 1;
        long long int v = b;
        while (a > v) {
            l <<= 1;
            v <<= 1;
        }
        if (a != v) {
            l >>= 1;
            v >>= 1;
        }
        //cout << l << '\t' << v << '\n';
        while (l && a >= b) {
            if (a >= v) {
                c += l;
                a -= v;
            }
            l >>= 1;
            v >>= 1;
            //cout << a << ' ' << '(' << l << ' ' << v << ')' << ' ' << c << '\n';
        }
        return sign ? -c : c;
    }
};