class Solution {
public:
    bool isValid(string s) {
        vector<char> v = vector<char>();
        for (char c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    v.push_back(c);
                    continue;
                default:
                    if (v.empty() || getL(c) != v.back()) return false;
                    v.pop_back();
                    continue;
            }
        }
        return v.empty();
    }

    char getL(char r) {
        switch (r) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
            default:
                return '\0';
        }
    }
};