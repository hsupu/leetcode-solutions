class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return size;
        
        vector<int>::iterator i, j, head, tail;
        head = nums.begin();
        tail = head + 1;
        for (i = tail; i != nums.end(); ++i) {
            for (j = head; j != tail; ++j) {
                if (*i == *j) {
                    break;
                }
            }
            if (j == tail) {
                *tail = *i;
                ++tail;
            }
        }
        return tail - head;
    }
};

static int x = []() { 
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    return 0; 
}();