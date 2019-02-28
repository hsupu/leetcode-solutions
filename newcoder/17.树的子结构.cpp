class Solution {
public:
    
    bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 || pRoot2) {
            if (pRoot1 && pRoot2) {
                if (pRoot1->val != pRoot2->val) return false;
                return IsSubtree(pRoot1->left, pRoot2->left) && IsSubtree(pRoot1->right, pRoot2->right);
            } else {
                return pRoot2 == nullptr; // 注意：子结构不一定是叶子节点
            }
        } else {
            return true;
        }
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == nullptr || pRoot2 == nullptr) return false;
        if (IsSubtree(pRoot1, pRoot2)) return true;
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};
