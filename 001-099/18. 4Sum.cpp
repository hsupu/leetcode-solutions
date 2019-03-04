class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        
        sort(nums.begin(), nums.end());
        
        int a, b, c, d, sum;
        
        vector<int>::iterator i, j, k, l, begin, end, i_end, j_end;
        begin = nums.begin();
        end = nums.end();
        i_end = end - 3;
        j_end = end - 2;
        for (i = begin; i != i_end; ) {
            a = *i;
            if (4 * a > target) break;
            for (j = i + 1; j != j_end; ) {
                b = *j;
                if (a + 3 * b > target) break;
                for (k = j + 1, l = end - 1; k < l; ) {
                    c = *k;
                    d = *l;
                    sum = a + b + c + d - target;
                    //cout << (i-begin) << ' ' << (j-begin) << ' ' << (k-begin) << ' ' << (l-begin) << " = " << sum << endl;
                    if (sum == 0) {
                        result.push_back(vector<int>({a, b, c, d}));
                        while (*(++k) == c && k < l) ;
                        while (*(--l) == d && k < l) ;
                    } else if (sum < 0) {
                        ++k;
                    } else if (sum > 0) {
                        --l;
                    }
                }
                do { ++j; } while (j != j_end && *j == b);
            }
            do { ++i; } while (i != i_end && *i == a);
        }
        return result;
    }
};