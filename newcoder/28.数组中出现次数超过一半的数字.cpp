class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        int n, c;
        vector<int>::iterator iter = numbers.begin(), end = numbers.end();
        n = *iter++;
        c = 1;
        while (iter != end) {
            if (c == 0) {
                n = *iter;
                c = 1;
            } else if (*iter == n) {
                c++;
            } else {
                c--;
            }
            iter++;
        }
        c = 0;
        for (int i : numbers) if (i == n) c++;
        return (2 * c > numbers.size()) ? n : 0;
    }
};
