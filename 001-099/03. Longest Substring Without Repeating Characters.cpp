class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const char* cstr = s.c_str();
        int longest = 0;
        int current = 0;
        
        int head = 0;
        int i = 0;
        
        for (char c = cstr[i]; c != '\0'; c = cstr[i]) {
            int j = i - 1;
            for (; j >= head; j--) {
                if (cstr[j] == c) {
                    break;
                }
            }
            if (j < i) {
                if (current > longest) longest = current;
                current += - (j - head);
                head = j + 1;
            } else {
                current++;
            }
            i++;
        }
        
        if (current > longest) longest = current;
        return longest;
    }
};
