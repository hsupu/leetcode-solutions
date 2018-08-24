class Solution {
public:

    int BinarySearch(vector<int>& sorted, int num) {
        int count = sorted.size();
        int a = 0, b = sorted.size() - 1;
        int avg;
        while (a <= b) {
            avg = (a + b) / 2;
            if (sorted[avg] == num) {
                return -1;
            } else if (sorted[avg] < num) {
                a = avg + 1;
            } else {
                b = avg - 1;
            }
        }
        return a;
    }

    bool containsDuplicate(vector<int>& nums) {
        vector<int> sorted;
        int pos;
        for (int num: nums) {
            pos = BinarySearch(sorted, num);
            cout << pos << endl;
            if (pos == -1) return true;
            sorted.insert(sorted.begin() + pos, num);
        }
        cout << endl;
        return false;
    }

};
