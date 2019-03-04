class Solution {
public:
    
    bool validateRow(vector<vector<char>>& board, int row) {
        set<char> s;
        for (int i = 0; i < 9; ++i) {
            char c = board[row][i];
            if (c == '.') continue;
            if (s.find(c) != s.end()) {
                printf("find %d,%d %c\n", row, i, c);
                return false;
            }
            s.insert(c);
        }
        return true;
    }
    
    bool validateColumn(vector<vector<char>>& board, int col) {
        set<char> s;
        for (int i = 0; i < 9; ++i) {
            char c = board[i][col];
            if (c == '.') continue;
            if (s.find(c) != s.end()) {
                printf("find %d,%d %c\n", i, col, c);
                return false;
            }
            s.insert(c);
        }
        return true;
    }
    
    bool validateBox(vector<vector<char>>& board, int row, int col) {
        set<char> s;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char c = board[3*row+i][3*col+j];
                if (c == '.') continue;
                if (s.find(c) != s.end()) {
                    printf("find %d,%d %c\n", 3*row+i, 3*col+j, c);
                    return false;
                }
                s.insert(c);
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            if (!validateRow(board, i) || !validateColumn(board, i) || !validateBox(board, i / 3, i % 3)) return false;
        }
        return true;
    }
};
