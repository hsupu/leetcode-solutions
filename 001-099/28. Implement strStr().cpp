class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int hsize, nsize;
        hsize = haystack.size();
        nsize = needle.size();
        if (hsize < nsize) return -1;
        
        // 接下来就是实现 KMP 算法了

        // jmp[i] = p 表示比较 i+1 失败时，下次比较 p
        int* jmp = new int[nsize];
        int k;
        k = jmp[0] = 0;
        for (int i = 1; i < nsize; ++i) {
            while (k && needle[k] != needle[i]) k = jmp[k - 1];
            if (needle[k] == needle[i]) {
                ++k;
            }
            jmp[i] = k;
        }
        
        //for (int i = 0; i < nsize; ++i) {
        //    printf("%d ", jmp[i]);
        //}
        //printf("\n");
            
        k = 0;
        for (int i = 0; i < hsize; ++i) {
            while (k && needle[k] != haystack[i]) k = jmp[k - 1];
            if (needle[k] == haystack[i]) {
                ++k;
                if (k == nsize) {
                    return i - nsize + 1;
                }
            }
        }
        
        return -1;
    }
};