class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *cur = pHead, *prv = nullptr, *nxt;
        while (cur) {
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        return prv;
    }
};
