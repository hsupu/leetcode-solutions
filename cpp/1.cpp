class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int>::iterator iter1 = nums.begin();
        for (int i = 0; iter1 != nums.end(); ++i, std::advance(iter1, 1)) {
            vector<int>::iterator iter2 = nums.begin();
            for (int j = 0; iter2 != iter1; ++j, std::advance(iter2, 1)) {
                if (*iter1 + *iter2 == target) {
                    result.push_back(j);
                    result.push_back(i);
                    return result;
                }
            }
        }
        return result;
    }
};
