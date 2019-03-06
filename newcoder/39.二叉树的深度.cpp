class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == nullptr) return 0;
        queue<pair<int, TreeNode*> > q;
        int maxval = 0;
        q.push(make_pair(1, pRoot));
        while (!q.empty()) {
            pair<int, TreeNode*> p = q.front(); q.pop();
            if (p.second == nullptr) continue;
            if (p.first > maxval) maxval = p.first;
            q.push(make_pair(p.first + 1, p.second->left));
            q.push(make_pair(p.first + 1, p.second->right));
        }
        return maxval;
    }
};

// 这里不用 pair 也能做，一次处理一层即可

int TreeDepth(TreeNode* pRoot) {
    if (pRoot == nullptr) return 0;
    queue<pair<int, TreeNode*> > q;
    int depth = 0;
    q.push(pRoot);
    while (!q.empty()) {
        depth++;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return depth;
}

// 递归写法比较简单

int TreeDepth(TreeNode* pRoot) {
    if (!pRoot) return 0;
    return max(1+TreeDepth(pRoot->left), 1+TreeDepth(pRoot->right));
}
