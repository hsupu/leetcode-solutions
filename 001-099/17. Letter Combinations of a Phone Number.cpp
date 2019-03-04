string* keyboard = new string[8]{
    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> a, b, *p, *q;
        b.push_back("");
        bool empty = true, use_a = true;
        for (char c : digits) {
            if (c == '1') continue;
            empty = false;
            if (use_a) {
                p = &a; q = &b;
            } else {
                p = &b; q = &a;
            }
            use_a = !use_a;
            p->clear();
            for (string s : *q) {
                for (char d : keyboard[c-'2']) {
                    p->push_back(s + d);
                }
            }
        }
        return (empty || !use_a) ? a : b;
    }
};