class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        
        string line[numRows];
        int num = 0;
        int add = 1;
        for (char c: s) {
            line[num] += c;
            if (num == numRows - 1) {
                add = -1;
            } else if (num == 0) {
                add = 1;
            }
            num += add;
        }
        string ret;
        for (string one: line) {
            ret += one;
        }
        return ret;
    }
};
