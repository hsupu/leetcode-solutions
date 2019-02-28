class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd, even;
        vector<int>::iterator iter = array.begin(), end = array.end();
        while (iter != end) {
            if (*iter % 2 == 0) {
                even.push_back(*iter);
            } else {
                odd.push_back(*iter);
            }
            iter++;
        }
        array.clear();
        array.insert(array.end(), odd.begin(), odd.end());
        array.insert(array.end(), even.begin(), even.end());
    }
};
