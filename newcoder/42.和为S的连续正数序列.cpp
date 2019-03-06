class Solution {
public:
    static void solution(vector<vector<int> >& ret, int a, int b) {
        vector<int> one;
        for (int j = a; j <= b; ++j) {
            one.push_back(j);
        }
        ret.push_back(one);
    }
    
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ret;
        if (sum == 1) return ret;
        
        int i = 1, tsum = 0;
        while (tsum < sum) {
            tsum += i;
            i++;
        }
        if (tsum == sum) {
            solution(ret, 1, i-1);
        }
        
        for (i = sqrt(sum); i > 1; --i) {
            if (i & 1) {
                // [x-i/2, x+i/2]
                // (2k+1)x = s, k = i/2
                int k = i/2;
                int x = sum/i;
                if (x*i == sum) {
                    int c = i/2;
                    solution(ret, x-c, x+c);
                }
            } else if (i > 3) {
                // [x-(i/2-1), x+1+(i/2-1)]
                // 2k(2x+1) = s, 2k = i/2
                int k = i/4;
                int x = (sum/(2*k)-1)/2;
                if ((2*k)*(2*x+1) == sum) {
                    int c = i/2-1;
                    solution(ret, x-c, x+1+c);
                }
            }
        }
        return ret; 
    }
};
