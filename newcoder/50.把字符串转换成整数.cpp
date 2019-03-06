class Solution {
public:
    int char2int(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        return -1;
    }
    int StrToInt(string str) {
        int size = str.size();
        if (size == 0) return 0;
        int ret = 0;
        int pvalue = 0;
        int pos;
        int sign;
        switch (str[0]) {
            case '+':
            case '-':
                sign = str[0] == '+' ? 1 : -1;
                pos = 1;
                break;
            default:
                sign = 1;
                pos = 0;
        }
        pvalue = char2int(str[pos]);
        if (pvalue == -1) return 0;
        ret = sign * pvalue;
        pos++;
        while (str[pos] != '\0') {
            pvalue = char2int(str[pos]);
            if (pvalue == -1) return 0;
            ret = ret * 10 + sign * pvalue;
            pos++;
        }
        return ret;
    }
};
