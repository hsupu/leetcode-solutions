class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int size = lists.size();
        int remain = size;
        while (remain) {
            int curi = 0;
            ListNode *cur = nullptr;
            for (int i = 0; i < size; ++i) {
                ListNode* list = lists[i];
                if (list == nullptr) continue;
                if (cur == nullptr || list->val < cur->val) {
                    curi = i;
                    cur = list;
                }
            }
            if (cur == nullptr) break; // case: [[]]
            tail->next = cur;
            tail = cur;
            if (!(lists[curi] = cur->next)) --remain;
        }
        return head->next;
    }
};
