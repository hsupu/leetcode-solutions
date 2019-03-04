class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* head2 = nullptr;
        ListNode* ns[k+1];
        ListNode* cur = head;
        int n = k;
        ns[0] = nullptr; // ns[0] for node before a group
        while (cur) {
            ns[n--] = cur;
            cur = cur->next;
            if (!n) {
                if (ns[0]) ns[0]->next = ns[1];
                for (int i = 1; i < k; ++i) {
                    ns[i]->next = ns[i+1];
                }
                ns[k]->next = cur;
                if (!ns[0]) head2 = ns[1];
                ns[0] = ns[k]; // next node before a group
                n = k;
            }
        }
        return (head2 == nullptr) ? head : head2;
    }
};
