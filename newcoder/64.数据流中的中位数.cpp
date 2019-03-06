class Solution {
private:
    priority_queue<int, vector<int>, less<int> > q; // 大顶堆，放从小到中
    priority_queue<int, vector<int>, greater<int> > p; // 小顶堆，放从中到大
public:
    void Insert(int num) {
        if (q.empty() || num <= q.top()) q.push(num);
        else p.push(num);
        
        // 奇数时中位数在 q
        if (q.size() - p.size() == 2) {
            p.push(q.top()); q.pop();
        } else if (p.size() - q.size() == 1) {
            q.push(p.top()); p.pop();
        }
    }

    double GetMedian() { 
        if (q.size() == p.size()) {
            return (q.top() + p.top()) / 2.0;
        } else {
            return (double)q.top();
        }
    }
};
