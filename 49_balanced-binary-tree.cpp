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
    int recur(TreeNode *root, bool &ret) {
        if (!root || !ret) {
            return 0;
        }

        int left = recur(root->left, ret);
        int right = recur(root->right, ret);
        if (left > right + 1 || right > left + 1)
            ret = false;
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        bool ret = true;
        recur(root, ret);
        return ret;
    }
};
