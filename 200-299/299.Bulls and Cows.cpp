class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        for (int i = 0; i < guess.length(); ++i) {
            if (guess[i] == secret[i]) {
                ++a;
                secret[i] = guess[i] = '-';
            }
        }
        for (int i = 0; i < guess.length(); ++i) {
            if (guess[i] == '-') continue;
            for (int j = 0; j < secret.length(); ++j) {
                if (guess[i] == secret[j]) {
                    ++b;
                    secret[j] = '-';
                    break;
                }
            }
        }
        stringstream ss;
        ss << a << 'A' << b << 'B';
        return ss.str();
    }
};
