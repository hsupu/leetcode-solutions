class Solution {
public:
    bool match_char(char c, char pattern) {
        if (c == '\0') return false;
        return pattern == '.' || c == pattern;
    }
    
    bool match(char* str, char* pattern) {
        if (*pattern == '\0') return *str == '\0';
        if (*(pattern+1) == '*') {
            if (match_char(*str, *pattern) && match(str + 1, pattern)) return true;
            return match(str, pattern + 2);
        } else {
            if (match_char(*str, *pattern)) {
                return match(str + 1, pattern + 1);
            } else {
                return false;
            }
        }
    }
};
