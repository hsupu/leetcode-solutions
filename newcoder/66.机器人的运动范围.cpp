class Solution {
public:
    int sum(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    
    int movingCount(int k, int rows, int cols) {
        if (rows < 1 || cols < 1) return 0;
        int c = 0;
        bool found[rows][cols];
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                found[i][j] = false;
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            int i = p.first, j = p.second;
            if (i < 0 || i >= rows || j < 0 || j >= cols) continue;
            if (found[i][j]) continue;
            if (sum(i) + sum(j) <= k) {
                c++;
                found[i][j] = true;
                q.push(make_pair(i-1, j));
                q.push(make_pair(i+1, j));
                q.push(make_pair(i, j-1));
                q.push(make_pair(i, j+1));
            }
        }
        return c;
    }
};
