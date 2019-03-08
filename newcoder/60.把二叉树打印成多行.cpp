class Solution {
public:
    vector<vector<int> > Print(TreeNode* root) {
        vector<vector<int> > ret;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> one(size, 0);
            for (int i = 0; i < size; ++i) {
                TreeNode *node;
                node = q.front(); q.pop();
                one[i] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ret.push_back(one);
        }
        return ret;
    }
};
