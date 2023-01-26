// leetcode 98
// Validate BST
// 验证一棵二叉搜索树的方法有两种
// 1. 考虑每个节点的性质
// 2. 考虑中序遍历的性质

class Solution {
public:
    bool valid(TreeNode* node, long mi, long mx) {
        if (!node) return true;
        
        if ((long)node->val <= mi || (long)node->val >= mx) return false;
        
        return valid(node->left, mi, node->val) && valid(node->right, node->val, mx);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, -2147483649, 2147483648);
    }
};


class Solution {
public:
    TreeNode* prev = nullptr;
    bool ans = true;
    
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);

        if (prev && node->val <= prev->val) {
            ans = false;
            return;
        }
        prev = node;
        
        inorder(node->right);
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
