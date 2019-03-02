class Solution {
public:
    static bool cmp(const string& a, const string& b) {
        return a + b < b + a;
    }
    
    string PrintMinNumber(vector<int> numbers) {
        vector<string> sv;
        for (int i : numbers) {
            sv.push_back(to_string(i));
        }
        sort(sv.begin(), sv.end(), cmp);
        stringstream ss;
        for (string& s : sv) {
            ss << s;
        }
        return ss.str();
    }
};
