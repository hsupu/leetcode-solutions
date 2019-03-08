class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        int checked[length];
        for (int i = 0; i < length; ++i) {
            checked[i] = 0;
        }
        *duplication = -1;
        for (int i = 0; i < length; ++i) {
            int n = numbers[i];
            if (n < 0 || n >= length) return false;
            if (checked[n]++) {
                if (*duplication == -1) {
                    *duplication = n;
                }
            }
        }
        return *duplication != -1;
    }
};
