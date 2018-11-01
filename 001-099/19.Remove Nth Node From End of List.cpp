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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sentry = new ListNode(0);
        sentry->next = head;
        
        ListNode* first = sentry;
        for (int i = 0; i < n; i++) {
            //if (first == nullptr) return nullptr;
            first = first->next;
        }
        
        ListNode* second = sentry;
        while (first->next != nullptr) {
            first = first->next;
            second = second->next; 
        }
        second->next = second->next->next;
        return sentry->next;
    }
};