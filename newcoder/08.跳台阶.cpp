class Solution {
public:
    int jumpFloor(int number) {
        int fib[40];
        fib[0] = 1; fib[1] = 1;
        for (int i = 2; i <= number; ++i) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[number];
    }
};
