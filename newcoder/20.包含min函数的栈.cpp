typedef struct node {
    int val;
    struct node *next; // in stack
    struct node *lesser;
    struct node *greater;
    node(int val) : val(val), next(NULL), lesser(NULL), greater(NULL) {}
} node_t;

class Solution {
public:
    void push(int value) {
        node_t *node = new node_t(value);
        
        node->next = head->next;
        head->next = node;
        
        node_t *ph = head->greater, *ph_prev = head;
        while (ph && ph->val < value) {
            ph_prev = ph;
            ph = ph->greater;
        }
        ph_prev->greater = node;
        node->lesser = ph_prev;
        node->greater = ph;
        if (ph) ph->lesser = node;
    }
    
    void pop() {
        node_t *node = head->next;
        head->next = node->next;
        node->lesser->greater = node->greater;
        if (node->greater) node->greater->lesser = node->lesser;
        delete node;
    }
    
    int top() {
        return head->next->val;
    }
    
    int min() {
        return head->greater->val;
    }

private:
    node_t *head = new node_t(0);
};
