class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int h = M.size();
        if (h == 0) {
            return M;
        }
        int w = M[0].size();
        
        int offsets[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1},
        };
        
        vector<vector<int>> *N = new vector<vector<int>>(h, vector<int>(w, 0));
        int c, v;
        int ni, nj;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                c = 1;
                v = M[i][j];
                for (int k = 0; k < 8; ++k) {
                    ni = i + offsets[k][0];
                    nj = j + offsets[k][1];
                    if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                    (*c)++;
                    (*v) += (*M)[ni][nj];
                }
                (*N)[i][j] = floor(v / c);
            }
        }
        
        return *N;
    }
};
