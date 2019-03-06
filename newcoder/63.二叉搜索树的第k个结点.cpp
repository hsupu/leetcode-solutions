class Solution {
public:
    void push_all_left_children(stack<TreeNode *> &s, TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
    
    TreeNode* KthNode(TreeNode* root, int k) {
        stack<TreeNode *> s;
        push_all_left_children(s, root);
        while (!s.empty()) {
            TreeNode *node = s.top(); s.pop();
            if (k == 1) return node;
            k--;
            push_all_left_children(s, node->right);
        }
        return nullptr;
    }
};
