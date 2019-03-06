class Solution {
public:
    void encode(TreeNode *root, stringstream &ss) {
        if (root) {
            ss << '[' << to_string(root->val) << ']';
            encode(root->left, ss);
            encode(root->right, ss);
        } else {
            ss << '#';
        }
    }
    
    char* Serialize(TreeNode *root) {
        stringstream ss;
        encode(root, ss);
        
        string s = ss.str();
        char* cs = new char[s.length() + 1];
        strcpy(cs, s.c_str());
        cs[s.length()] = 0;
        return cs;
    }
    
    TreeNode* decode(char **ps) {
        char *s = *ps;
        char magic = *s;
        *ps = s+1;
        if (magic == '#') return nullptr;
        
        s = *ps;
        int size = 0;
        while (*s != ']') {
            size++;
            s++;
        }
        *ps = s+1;
        int val = stoi(string(s - size, size));
        TreeNode *node = new TreeNode(val);
        node->left = decode(ps);
        node->right = decode(ps);
        return node;
    }
    
    TreeNode* Deserialize(char *str) {
        if (str == nullptr || *str == '\0') return nullptr;
        return decode(&str);
    }
};
