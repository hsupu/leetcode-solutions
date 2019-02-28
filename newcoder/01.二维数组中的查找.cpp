class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int asize = array.size();
        if (asize == 0) return false;
        int bsize = array[0].size();
        if (bsize == 0) return false;
        int i = 0, j = 0;
        while (true) {
            if (array[i][j] == target) {
                return true;
            } else if (array[i][j] > target) {
                for (int x = i - 1; x >= 0; --x) {
                    if (array[x][j] == target) {
                        return true;
                    } else if (array[x][j] < target) {
                        break;
                    }
                }
                for (int y = j - 1; y >= 0; --y) {
                    if (array[i][y] == target) {
                        return true;
                    } else if (array[i][y] < target) {
                        break;
                    }
                }
            }
            if (i + 1 == asize && j + 1 == bsize) break;
            if (i + 1 < asize) i++;
            if (j + 1 < bsize) j++;
        }
        return false;
    }
};
