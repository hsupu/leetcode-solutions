class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        ret.insert(ret.begin(), 1);
        
        int carry;
        for (int i = digits.size() - 1; i >= 0; --i) {
            ret[0] += digits[i];
            if (ret[0] == 10) {
                ret[0] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
            ret.insert(ret.begin(), carry);
        }
        if (carry == 0) ret.erase(ret.begin());
        return ret;
    }
};
