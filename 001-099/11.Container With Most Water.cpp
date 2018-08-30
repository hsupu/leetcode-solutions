class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        
        int i, j;
        i = 0;
        j = size - 1;
        
        int ih, jh, th;
        ih = height[i];
        jh = height[j];
        
        int best = 0;
        int cur;
        while (i < j) {
            if (ih < jh) {
                do {
                    ++i;
                    th = height[i];
                } while (th <= ih);
                ih = th;
            } else {
                do {
                    --j;
                    th = height[j];
                } while (th <= jh);
                jh = th;
            }
            cur = (j - i) * min(ih, jh);
            //cout << i << ' ' << j << ' ' << cur << "\n";
            if (cur > best) best = cur;
        }
        return best;
    }
};