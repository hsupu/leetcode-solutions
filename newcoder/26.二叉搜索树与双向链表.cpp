class Solution {
public:
    TreeNode* Convert(TreeNode* proot)
    {
        if (!proot) return proot;

        TreeNode *head, *lnode, *rnode;
        
        // 最左节点是头节点
        head = proot;
        while (head->left) head = head->left;
        
        // 注意初值
        lnode = nullptr;
        if (proot->left) {
            // 左节点的最右叶子节点->right = 根
            lnode = proot->left;
            while (lnode->right) lnode = lnode->right;
            Convert(proot->left);
        }
        
        rnode = nullptr;
        if (proot->right) {
            // 右节点的最左叶子节点->left = 根
            rnode = proot->right;
            while (rnode->left) rnode = rnode->left;
            Convert(proot->right);
        }
        
        if (lnode) {
            lnode->right = proot;
            proot->left = lnode;
        }
        if (rnode) {
            rnode->left = proot;
            proot->right = rnode;
        }
        return head;
    }
};
