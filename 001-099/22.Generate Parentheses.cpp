class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        recursive(list, string(2 * n, 0), 0, n, 0);
        return list;
    }
    
    void recursive(vector<string> &list, string s, int i, int lb, int rb) {
        if (rb) {
            if (lb == 0 && rb == 1) {
                //cout << i << '\t' << s.length() << '\n';
                s[i] = ')';
                list.push_back(s);
            } else {
                string s1 = string(s);
                s1[i] = ')';
                recursive(list, s1, i + 1, lb, rb - 1);
            }
        }
        if (lb) {
            string s1 = string(s);
            s1[i] = '(';
            recursive(list, s1, i + 1, lb - 1, rb + 1);
        }
    }
};
