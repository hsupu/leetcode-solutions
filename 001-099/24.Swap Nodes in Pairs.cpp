class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head && head->next) {
            ListNode *last, *curr, *next;
            last = head;
            curr = head->next->next;
            
            head->next->next = head;
            head = head->next;
            
            while (curr && curr->next) {
                if (curr->next) {
                    next = curr->next->next;
                    last->next = curr->next;
                    curr->next->next = curr;
                    last = curr;
                    curr = next;
                }
            }
            last->next = curr;
        }
        return head;
    }
};
