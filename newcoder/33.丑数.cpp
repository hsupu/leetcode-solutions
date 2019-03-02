class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) return 0;
        
        vector<int> iv(index, 0);
        iv[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int v2, v3, v5;
        for (int i = 1; i < index; ++i) {
            v2 = iv[i2]*2;
            v3 = iv[i3]*3;
            v5 = iv[i5]*5;
            int v = min(v2, min(v3, v5));
            iv[i] = v;
            if (v == v2) i2++;
            if (v == v3) i3++;
            if (v == v5) i5++;
        }
        return iv[index-1];
    }
};
