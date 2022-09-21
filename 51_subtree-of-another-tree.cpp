/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSame(TreeNode *root, TreeNode *sub) {
        if (!root && !sub) return true;
        if (!root || !sub) {
            if (root || sub) return false;
        }
        if (root->val != sub->val) return false;
        
        return isSame(root->left, sub->left) && isSame(root->right, sub->right);
    }
    void recur(TreeNode *root, TreeNode *sub, bool &ans) {
        if (!root) return ;
        if (isSame(root, sub)) {
            ans = true;
            return ;
        }
        recur(root->left, sub, ans);
        recur(root->right, sub, ans);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        recur(root, subRoot, ans);
        return ans;
    }
};
