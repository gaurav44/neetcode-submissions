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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto curr = root;
        if((p->val < curr->val) && (q->val < curr->val))
            return lowestCommonAncestor(curr->left, p, q);
        else if((p->val > curr->val) && (q->val > curr->val))
            return lowestCommonAncestor(curr->right, p, q);
        return curr;
    }
};
