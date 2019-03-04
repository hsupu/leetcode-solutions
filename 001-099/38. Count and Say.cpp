class Solution {
public:
    string countAndSay(int n) {
        string s = string("1");
        stringstream ss;
        while (--n) {
            ss.str("");
            int cnt = 0;
            char lst;
            for (char c : s) {
                if (c != lst) {
                    if (cnt) ss << cnt << lst;
                    cnt = 1;
                    lst = c;
                } else {
                    ++cnt;
                }
            }
            if (cnt) ss << cnt << lst;
            s = ss.str();
        }
        return s;
    }
};