class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        long a = x, b = 0;
        while (x) {
            b = b*10 + x%10;
            x /= 10;
        }
        cout << b << endl;
        return a == b;
    }
};
