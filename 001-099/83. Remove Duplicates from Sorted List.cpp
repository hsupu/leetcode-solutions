class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* unique = head;
        ListNode* cur = head->next;
        unique->next = nullptr;
        while (cur) {
            if (cur->val != unique->val) {
                unique->next = cur;
                unique = cur;
                cur = cur->next;
                unique->next = nullptr;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
