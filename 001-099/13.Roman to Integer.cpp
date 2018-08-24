class Solution {
public:

    int atomRomanToInt(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
    
    int romanToInt(string s) {
        int val = 0, old = 0, tmp;
        for (char c: s) {
            tmp = atomRomanToInt(c);
            if (old != 0 && old < tmp) {
                val = val - old * 2 + tmp;
            } else {
                val += tmp;
            }
            old = tmp;
        }
        return val;
    }
    
};
