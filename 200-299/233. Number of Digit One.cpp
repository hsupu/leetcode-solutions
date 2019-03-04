class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1) return 0;
        
        int count = 0, a, b;
        long m = 1;
        do {
            b = n % m;
            a = n / m;
            count += (a / 10) * m;
            switch (a % 10) {
                case 0:  break;
                case 1:  count += (b + 1); break;
                default: count += m; break;
            }
            m *= 10;
        } while (n >= m);
        return count;
    }
};
