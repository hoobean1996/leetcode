// leetcode 94
// Binary Tree Inorder Traversal 

// 递归实现
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> sk;
        
        vector<int> ans;
        
        while(root) {
            sk.push(root);
            root = root->left;
        }
        
        while(!sk.empty()) {
            auto top = sk.top(); sk.pop();
            ans.push_back(top->val);
            
            auto t = top->right;
            
            while(t) {
                sk.push(t);
                t = t->left;
            }
        }
        
        return ans;
    }
};