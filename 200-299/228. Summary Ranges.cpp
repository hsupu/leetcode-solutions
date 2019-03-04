class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.size() == 0) return ret;
        vector<int>::iterator iter = nums.begin();
        int a, b;
        a = b = *iter;
        stringstream ss;
        for (++iter; iter != nums.end(); ++iter) {
            if (*iter == b + 1) {
                ++b;
            } else {
                if (a < b) {
                    ss << a << "->" << b;
                } else {
                    ss << a;
                }
                ret.push_back(ss.str());
                ss.str("");
                a = b = *iter;
            }
        }
        if (a < b) {
            ss << a << "->" << b;
        } else {
            ss << a;
        }
        ret.push_back(ss.str());
        return ret;
    }
};
