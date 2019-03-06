class Solution {
public:
    TreeLinkNode* GetLeftest(TreeLinkNode* root) {
        while (root->left) root = root->left;
        return root;
    }
    
    TreeLinkNode* GetNext(TreeLinkNode* root) {
        bool pop_from_rchild = false;
        while (root) {
            if (!pop_from_rchild && root->right) {
                // 有右子
                return GetLeftest(root->right);
            }
            if (root->next) {
                if (root == root->next->left) {
                    // 是父的左子
                    return root->next;
                } else {
                    // 是父的右子
                    root = root->next;
                    pop_from_rchild = true;
                    continue;
                }
            }
            break;
        }
        return nullptr;
    }
};
