class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5) return false;
        int min = 14, max = 0, any = 0;
        set<int> s;
        for (int i : numbers) {
            if (i == 0) {
                any++;
                continue;
            }
            if (s.find(i) != s.end()) return false;
            s.insert(i);
            if (i < min) min = i;
            if (i > max) max = i;
        }
        return (max - min < 5) ? true : false;
    }
};
