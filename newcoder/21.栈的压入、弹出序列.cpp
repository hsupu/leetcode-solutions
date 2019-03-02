class Solution {
public:
    bool IsPopOrder(vector<int> pushV,  vector<int> popV) {
        stack<int> s;
        vector<int>::iterator pop_iter = popV.begin();
        for (int v : pushV) {
            s.push(v);
            while (!s.empty() && s.top() == *pop_iter) {
                pop_iter++;
                s.pop();
            }
        }
        return pop_iter == popV.end();
    }
};
