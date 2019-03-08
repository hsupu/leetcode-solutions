class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> ret;
        int a = 0, b = array.size()-1;
        while (a < b) {
            int av = array[a];
            int d = sum - av;
            while (a < b && d < array[b]) b--;
            if (d == array[b]) {
                ret.push_back(av);
                ret.push_back(d);
                break;
            }
            a++;
        }
        return ret;
    }
};
