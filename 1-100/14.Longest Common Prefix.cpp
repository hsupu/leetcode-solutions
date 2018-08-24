class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        
        vector<string>::iterator iter;
        string prefix = "";
        int pos = 0;
        char c;
        while (1) {
            iter = strs.begin();
            c = (*iter)[pos];
            for (; iter != strs.end(); ++iter) {
                if (pos == (*iter).length()) break;
                if (c != (*iter)[pos]) break;
            }
            if (iter != strs.end()) break;
            prefix += c;
            ++pos;
        }
        return prefix;
    }
};
