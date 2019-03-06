class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        stack<ListNode*> s1, s2;
        
        ListNode* cur;
        
        cur = pHead1;
        while (cur) {
            s1.push(cur);
            cur = cur->next;
        }
        cur = pHead2;
        while (cur) {
            s2.push(cur);
            cur = cur->next;
        }
        
        cur = nullptr;
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() != s2.top()) break;
            cur = s1.top();
            s1.pop(); s2.pop();
        }
        return cur;
    }
};

// 更好的方法是扫两遍，第一遍求出长度差，然后第二遍长的那一个先走到等长
