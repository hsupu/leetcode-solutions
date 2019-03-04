class Solution {
public:
    string intToRoman(int num) {
        stringstream ss;
        while (num) {
            if (cmpAndOutput(num, ss, 1000, "M")) continue;
            if (cmpAndOutput(num, ss, 900, "CM")) continue;
            if (cmpAndOutput(num, ss, 500, "D")) continue;
            if (cmpAndOutput(num, ss, 400, "CD")) continue;
            if (cmpAndOutput(num, ss, 100, "C")) continue;
            if (cmpAndOutput(num, ss, 90, "XC")) continue;
            if (cmpAndOutput(num, ss, 50, "L")) continue;
            if (cmpAndOutput(num, ss, 40, "XL")) continue;
            if (cmpAndOutput(num, ss, 10, "X")) continue;
            if (cmpAndOutput(num, ss, 9, "IX")) continue;
            if (cmpAndOutput(num, ss, 5, "V")) continue;
            if (cmpAndOutput(num, ss, 4, "IV")) continue;
            if (cmpAndOutput(num, ss, 1, "I")) continue;
        }
        return ss.str();
    }

    bool cmpAndOutput(int& num, stringstream& ss, int unit, string literal) {
        if (num >= unit) {
            ss << literal;
            num -= unit;
            return true;
        }
        return false;
    }
};