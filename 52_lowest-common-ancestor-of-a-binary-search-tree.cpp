/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void check(TreeNode *r, TreeNode *p, TreeNode *q, int &count) {
        if (!r) return ;
        if (r->val == p->val || r->val == q->val) count++;
        check(r->left, p, q, count);
        check(r->right, p, q, count);
    }
    void recur(TreeNode *r, TreeNode *p, TreeNode *q, TreeNode** ans) {
        if (!r) return ;
        int temp = 0;
        check(r, p, q, temp);
        if (temp == 2) {
            *ans = r;
            recur(r->left, p, q, ans);
            recur(r->right, p, q, ans);
        }
        
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        recur(root, p, q, &ans);
        return ans;
    }
};
