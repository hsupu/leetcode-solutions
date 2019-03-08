class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
        int size = data.size();
        int state = 0;
        for (int i = 0; i < size; ++i) {
            int n = data[i];
            bool found = false;
            for (int j = i+1; j < size; ++j) {
                if (data[j] == n) {
                    data[j] = data[size-1];
                    size--;
                    found = true;
                    break;
                }
            }
            if (!found) {
                switch (state) {
                    case 0:
                        *num1 = n;
                        state = 1;
                        break;
                    case 1:
                        *num2 = n;
                        return;
                }
            }
        }
    }
};

// 可以用异或运算，因为异或一个数两次则抵消，而异或两个不同的数，一定有某个位被置 1，根据每个数里该位是 1 是 0 可分为两组，且必然分开了两个不同的数，再分别异或一遍，得解。
