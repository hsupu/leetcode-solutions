class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> rset;
        if (k == 0) {
            return rset;
        }
        int size = arr.size();
        // binary search for x in [i, j)
        int i = 0, j = size, m, mv;
        while (i < j) {
            m = (i + j) / 2;
            mv = arr[m];
            if (mv == x) {
                break;
            }
            if (mv < x) {
                i = m + 1;
            } else {
                j = m;
            }
        }
        // m is the closest one to x
        if (i >= j) {
            if (j == 0) {
                m = j;
            } else {
                if ((arr[j - 1] - x) <= (arr[j] - x)) {
                    m = j - 1;
                } else {
                    m = j;
                }
            }
        }
        printf("%d\n", m);
        // pick k
        i = m;
        j = m + 1;
        for (int l = k - 1; l > 0; --l) {
            if (i == 0) {
                j += l;
                break;
            }
            if (j == size) {
                i -= l;
                break;
            }
            if ((x - arr[i - 1]) <= (arr[j] - x)) {
                i--;
            } else {
                j++;
            }
        }
        // output [i, j)
        for (; i < j; ++i) {
            rset.push_back(arr[i]);
        }
        return rset;
    }
};