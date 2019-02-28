class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == nullptr) return;
        TreeNode *left = pRoot->left, *right = pRoot->right;
        pRoot->left = right;
        pRoot->right = left;
        Mirror(left); Mirror(right);
    }
};
