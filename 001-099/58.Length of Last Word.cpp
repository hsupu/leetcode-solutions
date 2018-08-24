class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = 0, flag = 0;
        for (char c: s) {
            if (c == ' ') {
                flag = 1;
            } else if (flag == 1) {
                n = 1;
                flag = 0;
            } else {
                ++n;
            }
        }
        return n;
    }
};
