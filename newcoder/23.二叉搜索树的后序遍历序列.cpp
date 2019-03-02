class Solution {
public:
    
    bool foo(vector<int>::iterator itbegin, vector<int>::iterator itend) {
        if (itbegin == itend) return true;
        vector<int>::iterator last = itend - 1;
        int root = *last;
        vector<int>::iterator iter1 = itbegin;
        while (iter1 != last) {
            if (*iter1 >= root) break;
            iter1++;
        }
        if (!foo(itbegin, iter1)) return false;
        vector<int>::iterator iter2 = iter1;
        while (iter2 != last) {
            if (*iter2 <= root) return false;
            iter2++;
        }
        if (!foo(iter1, last)) return false;
        return true;
    }
    
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        return foo(sequence.begin(), sequence.end());
    }
};
