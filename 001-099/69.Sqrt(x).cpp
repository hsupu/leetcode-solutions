class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        int a = 1, b = x, mid, tmp;
        //int count = 50;
        while (a <= b) {
            //if (count == 0) break;
            //--count;
            
            mid = a + (b-a) / 2;
            //cout << a << '\t' << b << '\t' << mid << endl;
            tmp = x / mid;
            if (tmp < mid) {
                b = mid - 1;
            } else if (tmp == mid) {
                return mid;
            } else if (a == mid) {
                if (x / b < b) {
                    return a;
                } else {
                    return b;
                }
            } else {
                a = mid;
            }
        }
        //cout << endl;
        return mid;
    }
};
