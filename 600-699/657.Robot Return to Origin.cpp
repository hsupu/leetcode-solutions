class Solution {
public:
    bool judgeCircle(string moves) {
        int size = moves.size();
        if (size % 2 == 1) {
            return false;
        }
        int x = 0;
        int y = 0;
        for (char c : moves) {
            switch (c) {
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
            }
        }
        return x == 0 && y == 0;
    }
};

