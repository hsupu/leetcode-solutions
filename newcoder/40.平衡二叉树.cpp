class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        queue<TreeNode*> q;
        int state = 0;
        if (pRoot) q.push(pRoot);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front(); q.pop();
                if (state == 0) {
                    if (!node->left || !node->right) {
                        if (!node->left && !node->right) {
                            state = 2; // 至多再多一层
                        } else {
                            state = 1; // 至多再多两层
                        }
                    }
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (state == 1) {
                state = 2;
                continue;
            }
            if (state == 2) {
                while (!q.empty()) {
                    TreeNode *node = q.front(); q.pop();
                    if (node->left || node->right) return false;
                }
                return true;
            }
        }
        return true;
    }
};

// 可以用递归的思路，从叶子往上返回平衡二叉树的高度

public class Solution {
    public boolean IsBalanced_Solution(TreeNode root) {
        return getDepth(root) != -1;
    }
     
    private int getDepth(TreeNode root) {
        if (root == null) return 0;
        int left = getDepth(root.left);
        if (left == -1) return -1;
        int right = getDepth(root.right);
        if (right == -1) return -1;
        return Math.abs(left - right) > 1 ? -1 : 1 + Math.max(left, right);
    }
}
