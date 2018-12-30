class Solution {
public:
    
    int bit(string s, int len, int pos) {
        if (pos < 0 || pos >= len) return 0;
        return s[pos] - '0';
    }
    
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        int t = max(m, n) + 1;
        
        char * cs = new char[t + 1];
        cs[t] = '\0';
        
        int i = m - 1;
        int j = n - 1;
        
        int ac, bc, current, carry = 0;
        for (int k = t - 1; k >= 0; --i, --j, --k) {
            ac = bit(a, m, i);
            bc = bit(b, n, j);
            current = ac + bc + carry;
            cs[k] = '0' + (current & 0x1);
            carry = (current & 0x2) >> 1;
        }
        return (cs[0] == '0') ? string(cs + 1) : string(cs);
    }
};
