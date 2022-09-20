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
    void recur(TreeNode *root, int *ret, int level) {
        if (!root) {
            *ret = max(*ret, level);
            return ;
        }
        recur(root->left, ret, level + 1);
        recur(root->right, ret, level + 1);
    }
    int maxDepth(TreeNode* root) {
        int ret = 0;
        
        recur(root, &ret, 0);
        return ret;
    }
};
