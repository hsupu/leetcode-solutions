class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int len = A[0].size();
        int deletion = 0;
        char* check = new char[len];
        for (int i = 0; i < len; ++i) {
            check[i] = ' ';
        }
        for (auto a : A) {
            for (int i = 0; i < len; ++i) {
                if (check[i]) {
                    if (check[i] > a[i]) {
                        check[i] = 0;
                        ++deletion;
                    } else {
                        check[i] = a[i];
                    }
                }
            }
        }
        return deletion;
    }
};