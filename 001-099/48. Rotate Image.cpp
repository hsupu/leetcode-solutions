class Solution {
public:
    void foo(vector<vector<int>>& matrix, int n, int r) {
        if (n <= 2*r) return;
        
        int lu[2] = {  r,   r};
        int ru[2] = {  r, n-r};
        int ld[2] = {n-r,   r};
        int rd[2] = {n-r, n-r};
        int t[4];
        for (int i = 0, e = n-2*r; i < e; ++i) {
            t[0] = matrix[lu[0]]  [lu[1]+i];
            t[1] = matrix[ru[0]+i][ru[1]];
            t[2] = matrix[rd[0]]  [rd[1]-i];
            t[3] = matrix[ld[0]-i][ld[1]];
            matrix[lu[0]]  [lu[1]+i] = t[3];
            matrix[ru[0]+i][ru[1]]   = t[0];
            matrix[rd[0]]  [rd[1]-i] = t[1];
            matrix[ld[0]-i][ld[1]]   = t[2];
        }
        
        foo(matrix, n, r+1);
    }
    
    void rotate(vector<vector<int>>& matrix) {
        foo(matrix, matrix.size()-1, 0);
    }
};
