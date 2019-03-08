class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        int p[n], q[n];
        p[0] = 1;
        q[n-1] = 1;
        for (int i = 1; i < n; ++i) {
            p[i] = p[i-1] * A[i-1];
            q[n-1-i] = q[n-i] * A[n-i];
        }
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            ret.push_back(p[i] * q[i]);
        }
        return ret;
    }
};
