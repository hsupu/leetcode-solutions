class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* node1 = pListHead;
        for (int i = 0; i < k; ++i) {
            if (node1 == nullptr) return nullptr;
            node1 = node1->next;
        }
        ListNode* node2 = pListHead;
        while (node1) {
            node1 = node1->next;
            node2 = node2->next;
        }
        return node2;
    }
};
