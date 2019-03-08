class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (!pHead) return nullptr;
        ListNode *head = pHead;
        ListNode *last = nullptr;
        ListNode *cur = head;
        bool dup;
        while (cur) {
            dup = false;
            ListNode *test = cur;
            while (test->next) {
                if (test->next->val != cur->val) break;
                test = test->next;
                dup = true;
            }
            if (dup) {
                if (head == cur) {
                    head = test->next;
                    last = nullptr;
                } else {
                    last->next = test->next;
                }
            } else {
                last = cur;
            }
            cur = test->next;
        }
        return head;
    }
};
