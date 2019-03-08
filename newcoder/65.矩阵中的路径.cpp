class Solution {
public:
    static int pos(int rows, int cols, int row, int col) {
        return row * cols + col;
    }
    
    static bool hasPath(char *matrix, int rows, int cols, int y, int x, const char *s) {
        if (*s == '\0') return true;
        if (y < 0 || y >= rows || x < 0 || x >= cols) return false;
        int p = pos(rows, cols, y, x);
        if (matrix[p] != *s) return false;
        matrix[p] = '\0';
        bool has = hasPath(matrix, rows, cols, y-1, x, s+1)
                || hasPath(matrix, rows, cols, y+1, x, s+1)
                || hasPath(matrix, rows, cols, y, x-1, s+1)
                || hasPath(matrix, rows, cols, y, x+1, s+1);
        matrix[p] = *s;
        return has;
    }
    
    bool hasPath(char *matrix, int rows, int cols, const char *s) {
        if (s == nullptr || *s == '\0') return true;
        
        for (int y = 0; y < rows; ++y) {
            for (int x = 0; x < cols; ++x) {
                int p = pos(rows, cols, y, x);
                if (matrix[p] == *s) {
                    if (hasPath(matrix, rows, cols, y, x, s)) return true;
                }
            }
        }
        return false;
    }
};
