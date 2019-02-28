class Solution {
public:
     int NumberOf1(int n) {
         int c = 0;
         unsigned int t = 1;
         while (t > 0) {
             if (n & t) c++;
             t <<= 1;
         }
         return c;
     }
};
