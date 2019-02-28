class Solution {
public:
    
    void foo(vector<vector<int> >& matrix, int rows, int cols, vector<int>& ret, int level) {
        int lb = level, rb = cols - level;
        int tb = level, bb = rows - level;
        if (lb > rb || tb > bb) return;
        if (lb == rb) {
            for (int i = tb; i <= bb; ++i) {
                ret.push_back(matrix[i][lb]);
            }
            return;
        }
        if (tb == bb) {
            for (int i = lb; i <= rb; ++i) {
                ret.push_back(matrix[tb][i]);
            }
            return;
        }
        for (int i = lb; i < rb; ++i) {
            ret.push_back(matrix[tb][i]);
        }
        for (int i = tb; i < bb; ++i) {
            ret.push_back(matrix[i][rb]);
        }
        for (int i = rb; i > lb; --i) {
            ret.push_back(matrix[bb][i]);
        }
        for (int i = bb; i > tb; --i) {
            ret.push_back(matrix[i][lb]);
        }
        foo(matrix, rows, cols, ret, level+1);
    }
    
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        if (!matrix.empty() && !matrix[0].empty()) {
            foo(matrix, matrix.size()-1, matrix[0].size()-1, ret, 0);
        }
        return ret;
    }
};
