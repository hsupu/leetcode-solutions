// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int a = 1, b = n, m;
        while (a < b) {
            m = a + (b-a) / 2;
            if (isBadVersion(m)) {
                b = m;
            } else {
                a = m + 1;
            }
        }
        return a;
    }
};
