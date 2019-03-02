class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k < 1 || k > input.size()) return vector<int>();
        
        priority_queue<int, vector<int>, less<int> > q;
        vector<int>::iterator iter = input.begin(), end = input.end();
        for (int i = 0; i < k; i++, iter++) {
            q.push(*iter);
        }
        while (iter != end) {
            q.push(*iter);
            q.pop();
            iter++;
        }
        vector<int> ret(k, 0);
        for (int i = k - 1; i >= 0; i--) {
            ret[i] = q.top();
            q.pop();
        }
        return ret;
    }
};
