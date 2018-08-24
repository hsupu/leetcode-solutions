class Solution {
public:
    
    int smaller(int a, int b) {
        return a < b ? a : b;
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int w1 = abs(A-C), w2 = abs(E-G), h1 = abs(B-D), h2 = abs(F-H);
        int a1 = w1 * h1, a2 = w2 * h2;
        if (A < G && B < H && C > E && D > F) {
            int w3 = abs(A-G), w4 = abs(C-E), h3 = abs(B-H), h4 = abs(D-F);
            w3 = smaller(smaller(w1, w2), smaller(w3, w4));
            h3 = smaller(smaller(h1, h2), smaller(h3, h4));
            int a3 = w3 * h3;
            cout << a1 << '\t' << a2 << '\t' << a3 << endl;
            return a1 + a2 - a3;
        } else {
            return a1 + a2;
        }
    }
};
