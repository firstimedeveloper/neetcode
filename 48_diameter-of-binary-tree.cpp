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
       4
 -7                                 -3
 - -           -9                                   -3
         9                -7                     -4      -
      6 -           -6              -6               - -
    0     6        5     -       9      -
  - -1   -4 -   -   -           -2  
    
 */
class Solution {
public:
    int recur(TreeNode *root, int &ret) {
        if (!root) {
            return 0;
        }
        int left = recur(root->left, ret);
        int right = recur(root->right, ret);
        ret = max(ret, left + right);
        return 1 + max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ret = 0;
        recur(root, ret);
        return ret;
    }
};
