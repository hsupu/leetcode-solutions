/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* last = head;
        ListNode* node = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int cur = carry;
            if (l1 != nullptr) {
                cur += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                cur += l2->val;
                l2 = l2->next;
            }
            if (cur >= 10) {
                cur -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            
            node = new ListNode(cur);
            last->next = node;
            last = node;
        }
        if (head->next == nullptr) {
            return head;
        } else {
            return head->next;
        }
    }
};
