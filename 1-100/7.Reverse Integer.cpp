class Solution {
public:
    int reverse(int x) {
        int y = 0;
        int y0, y1, t;
        while (x) {
            y0 = y;
            t = x % 10;
            y = y * 10 + t;
            y1 = (y - t) / 10;
            if (y0 != y1) return 0;
            x /= 10;
        }
        return y;
    }
};
