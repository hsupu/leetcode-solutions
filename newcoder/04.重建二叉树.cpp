/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* foo(vector<int>::iterator pre, vector<int>::iterator preend, vector<int>::iterator vin, vector<int>::iterator vinend) {
        if (pre == preend) return nullptr;
        int root_value = *pre++;
        TreeNode* root = new TreeNode(root_value);
        
        vector<int>::iterator pre1 = pre, vin1 = vin;
        while (*vin1 != root_value) {
            pre1++;
            vin1++;
        }
        root->left = foo(pre, pre1, vin, vin1);
        
        vin1++;
        root->right = foo(pre1, preend, vin1, vinend);
        
        return root;
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        return foo(pre.begin(), pre.end(), vin.begin(), vin.end());
    }
};
