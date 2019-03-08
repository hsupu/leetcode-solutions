class Solution {
public:
    int char2int(char c) {
        if (c < '0' || c > '9') return -1;
        return c - '0';
    }
    
    bool is_int(char* s, char* end, bool require_one) {
        if (s == end) return !require_one;
        int sign;
        switch (*s) {
            case '+':
                sign = 1;
                s++;
                break;
            case '-':
                sign = -1;
                s++;
                break;
        }
        if (require_one) return s != end;
        return true;
    }
    
    bool isNumeric(char* s) {
        int state = 0;
        int sign = false;  // 是否出现过正负号
        int dec = false;   // 是否出现过小数点
        int index = false; // 是否出现过指数 e
        
        char *a = s, *b = s;
        while (true) {
            char c = *b;
            switch (c) {
                case '\0':
                    return is_int(a, b, true);
                case '+':
                case '-':
                    if (sign) return false;
                    sign = true;
                    break;
                case '.':
                    if (dec || index) return false;
                    if (!is_int(a, b, false)) {
                        return false;
                    }
                    dec = true;
                    sign = true;
                    a = b + 1;
                    break;
                case 'e':
                case 'E':
                    if (index) return false;
                    if (!is_int(a, b, true)) return false;
                    sign = false;
                    dec = true;
                    a = b + 1;
                    break;
                default:
                    if (char2int(c) == -1) return false;
                    sign = true;
            }
            b++;
        }
    }
};
