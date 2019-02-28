class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        ListNode* temp;
        while (pHead1 || pHead2) {
            if (pHead1 && pHead2) {
                if (pHead1->val < pHead2->val) {
                    temp = pHead1->next;
                    node->next = pHead1;
                    pHead1 = temp;
                } else {
                    temp = pHead2->next;
                    node->next = pHead2;
                    pHead2 = temp;
                }
                node = node->next;
            } else {
                if (pHead1) {
                    node->next = pHead1;
                } else {
                    node->next = pHead2;
                }
                break;
            }
        }
        return head->next;
    }
};
