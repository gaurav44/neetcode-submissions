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

        TreeNode* lca = nullptr;

        auto dfs = [&](auto&& self, TreeNode* node) {
            if(!node) return;

            // both p and q are less than node go left
            if(p->val < node->val && q->val < node->val) {
                self(self, node->left);
                return;
            } 
            
            // both p and q are greater than node
            if(p->val > node->val && q->val > node->val) {
                self(self, node->right);
                return;
            }
            lca = node;
        };

        dfs(dfs, root);
        return lca;
        
    }
};
