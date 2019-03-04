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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_first = NULL, *odd_last = NULL, *even_first = NULL, *even_last = NULL, *current = head;
        bool is_odd = true;
        if (current) {
            odd_first = current;
            odd_last = current;
            current = current->next;
            odd_last->next = NULL;
        } else {
            return head; // NULL
        }
        if (current) {
            even_first = current;
            even_last = current;
            current = current->next;
            even_last->next = NULL;
        }
        while (current != NULL) {
            if (is_odd) {
                odd_last->next = current;
                odd_last = current;
                current = current->next;
                odd_last->next = NULL;
            } else {
                even_last->next = current;
                even_last = current;
                current = current->next;
                even_last->next = NULL;
            }
            is_odd = !is_odd;
        }
        odd_last->next = even_first;
        return odd_first;
    }
};
