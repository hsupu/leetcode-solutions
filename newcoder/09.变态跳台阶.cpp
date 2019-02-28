class Solution {
public:
    int jumpFloorII(int number) {
        return pow(2, number-1); // f(n) = 2f(n-1), f(1) = 1
    }
};
