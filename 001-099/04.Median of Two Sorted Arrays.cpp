class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> * a, * b;
        int an, bn;
        a = &nums1;
        b = &nums2;
        an = a->size();
        bn = b->size();
        
        // ensure bi >= 0
        if (an > bn) {
            printf("exchange\n");
            
            vector<int> * t = a;
            a = b;
            b = t;
            
            int tn = an;
            an = bn;
            bn = tn;
        }
        
        int sum = an + bn;
        bool even = sum % 2 == 0;
        
        // guess range
        int al, ar;
        al = 0;
        ar = an - 1;
        
        // cut before the index
        int ai, bi;
        
        int almax, armin, blmax, brmin;
        
        while (true) {
            // [0,^1,2]
            // [0,1,^2,3,]

            // ai + bi (+ 1) == an - ai + bn - bi
            ai = (al+ar+1) / 2;
            bi = sum / 2 - ai;
            
            almax = ai == 0 ? INT_MIN : (*a)[ai-1];
            armin = ai == an ? INT_MAX : (*a)[ai];
            
            blmax = bi == 0 ? INT_MIN : (*b)[bi-1];
            brmin = bi == bn ? INT_MAX : (*b)[bi];
            
            printf("ai=%d bi=%d a[lmax=%d,rmin=%d] b[lmax=%d,rmin=%d]\n", ai, bi, almax, armin, blmax, brmin);
            
            if (almax <= brmin) {
                if (blmax <= armin) {
                    if (even) {
                        int x = (almax > blmax) ? almax : blmax;
                        int y = (armin < brmin) ? armin : brmin;
                        return (x + y) / 2.0;
                    } else {
                        return (double) ((armin < brmin) ? armin : brmin);
                    }
                } else {
                    printf("al: %d=>%d\n", al, ai+1);
                    al = ai+1;
                }
            } else {
                printf("ar: %d=>%d\n", ar, ai-1);
                ar = ai-1;
            }
        }
    }
};
