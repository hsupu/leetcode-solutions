class Solution {
public:
    
    int foo(vector<int>& t, int n, int l) {
        int d = pow(10, l);
        int q = n / d, r = n % d;
        int c = 0;
        if (q > 1) c += d;
        else if (q == 1) c += r+1;
        if (l) {
            c += q*t[l-1];
            c += foo(t, r, l-1);
        }
        return c;
    }
    
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n == 0) return 0;
        vector<int> t;
        int l = 1;
        unsigned int i = 1, last = 0;
        while (i*10 <= n) {
            last = i + 10*last;
            t.push_back(last);
            i *= 10;
            l++;
        }
        return foo(t, n, l-1);
    }
};
