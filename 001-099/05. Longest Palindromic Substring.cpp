class Solution {
public:
    string longestPalindrome(string s) {
        std::string::iterator best_a, best_b;
        int best_l;
        if (s.size()) {
            best_a = best_b = s.begin();
            best_l = 1;
        } else {
            return s;
        }
        std::string::iterator a, b, i, j;
        int l = 0;
        for (i = s.begin(); i != s.end(); ++i) {
            for (j = s.begin(); j != i; ++j) {
                if (*j == *i) {
                    //printf("%d %d\n", j - s.begin(), i - s.begin());
                    a = j + 1;
                    b = i - 1;
                    while (a < b) {
                        if (*a != *b) {
                            break;
                        }
                        ++a;
                        --b;
                    }
                    if (a >= b) {
                        l = i - j + 1;
                        //printf("match %d\n", l);
                        if (l > best_l) {
                            best_a = j;
                            best_b = i;
                            best_l = l;
                        }
                        break;
                    }
                }
            }
        }
        //printf("best %d %d %d\n", best_l, best_a - s.begin(), best_b - s.begin());
        return string(best_a, best_b + 1);
    }
};