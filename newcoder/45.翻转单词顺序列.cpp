class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        int p1 = 0, p2 = 0;
        while (str[p2] != '\0') {
            if (str[p2] == ' ') {
                if (p1 < p2) reverse(str.begin() + p1, str.begin() + p2);
                p1 = p2 + 1;
            }
            p2++;
        }
        if (p1 < p2) reverse(str.begin() + p1, str.begin() + p2);
        return str;
    }
};
