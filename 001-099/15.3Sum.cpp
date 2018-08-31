class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        
        sort(nums.begin(), nums.end());
        
        int a, b, c, sum;
        
        vector<int>::iterator i, j, k, begin, end, i_end;
        begin = nums.begin();
        end = nums.end();
        i_end = end - 2;
        for (i = begin; i != i_end; ++i) {
            a = *i;
            if (a > 0) break;
            if (i != begin && *(i - 1) == a) continue;
            for (j = i + 1, k = end - 1; j < k; ) {
                b = *j;
                c = *k;
                sum = a + b + c;
                //cout << (i-begin) << ' ' << (j-begin) << ' ' << (k-begin) << " = " << sum << endl;
                if (sum == 0) {
                    result.push_back(vector<int>({a, b, c}));
                    while (*(++j) == b && j < k) ;
                    while (*(--k) == c && j < k) ;
                } else if (sum < 0) {
                    ++j;
                } else if (sum > 0) {
                    --k;
                }
            }
        }
        return result;
    }
};