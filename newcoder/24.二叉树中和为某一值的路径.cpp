/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

typedef struct node {
    struct node *parent;
    int sum;
    TreeNode* inner;
    bool is_leaf;
    node(struct node* parent, TreeNode* inner) {
        this->parent = parent;
        this->inner = inner;
        if (parent) {
            this->sum = parent->sum + inner->val;
        } else {
            this->sum = inner->val;
        }
        this->is_leaf = !(inner->left || inner->right);
    }
} node_t;

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        stack<vector<int> > ret;
        queue<node_t*> q;
        if (root) q.push(new node_t(nullptr, root));
        while (!q.empty()) {
            node_t *node = q.front(); q.pop();
            if (node->is_leaf) {
                if (node->sum == expectNumber) {
                    stack<int> s;
                    node_t *tnode = node;
                    while (tnode) {
                        s.push(tnode->inner->val);
                        tnode = tnode->parent;
                    }
                    vector<int> v;
                    while (!s.empty()) {
                        v.push_back(s.top());
                        s.pop();
                    }
                    ret.push(v);
                }
            } else {
                if (node->inner->left) q.push(new node_t(node, node->inner->left));
                if (node->inner->right) q.push(new node_t(node, node->inner->right));
            }
        }
        vector<vector<int> > ret0;
        while (!ret.empty()) {
            ret0.push_back(ret.top()); ret.pop();
        }
        return ret0;
    }
};
