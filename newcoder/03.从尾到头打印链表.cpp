/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    
    void foo(vector<int>& ret, ListNode* node) {
        if (node->next) {
            foo(ret, node->next);
        }
        ret.push_back(node->val);
    }
    
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        if (head) {
            foo(ret, head);
        }
        return ret;
    }
};
