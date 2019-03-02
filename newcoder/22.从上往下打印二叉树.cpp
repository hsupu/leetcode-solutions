class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> q;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            ret.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return ret;
    }
};

// std::queue 没有 push_back / pop_front，而是 push / pop