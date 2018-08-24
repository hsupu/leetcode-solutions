class Solution {
public:
    int myAtoi(string str) {
        long ret = 0;
        
        int lbound = 0;
        while (str[lbound] == ' ') ++lbound;
        
        long m;
        switch (str[lbound]) {
            case '-':
                ++lbound;
                m = -1;
                break;
            case '+':
                ++lbound;
            default:
                m = 1;
        }
        
        int rbound = lbound;
        while (str[rbound] >= '0' && str[rbound] <= '9') ++rbound;
        
        for (int pos = rbound - 1; pos >= lbound; --pos, m *= 10) {
            //cout << str[pos];
            ret += (str[pos] - '0') * m;
            if (ret > 2147483647) {
                ret = 2147483647;
                break;
            } else if (ret < -2147483648) {
                ret = -2147483648;
                break;
            }
            //cout << ret << endl;
        }
        
        //cout << endl;
        return (int)ret;
    }
};
