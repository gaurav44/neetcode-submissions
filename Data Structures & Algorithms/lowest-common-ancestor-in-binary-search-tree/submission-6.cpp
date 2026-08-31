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

        auto dfs = [&](auto&& self, TreeNode* node) -> TreeNode* {
            if(!node) return nullptr;

            if(p->val < node->val && q->val < node->val) return self(self, node->left);

            if(p->val > node->val && q->val > node->val) return self(self, node->right);

            return node;
        };

        return dfs(dfs, root);
        
    }
};
