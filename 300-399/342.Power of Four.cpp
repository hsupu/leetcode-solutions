class Solution {
public:
    bool isPowerOfFour(int num) {
        // WARNING: priority of '&' is lower than '=='
        return (num > 0
            && ((num & (num-1)) == 0) // only one 1
            && ((num & 0x55555555) != 0) // 5 is 0101b, to get rid of those power of 2
        );
    }
};
