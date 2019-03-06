class Solution {
public:
    bool isEqual(TreeNode *a, TreeNode *b) {
        if (a || b) {
            if (a && b) {
                if (a->val != b->val) return false;
                return isEqual(a->left, b->right) && isEqual(a->right, b->left);
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
    
    bool isSymmetrical(TreeNode* root) {
        if (!root) return true;
        return isEqual(root->left, root->right);
    }
};
