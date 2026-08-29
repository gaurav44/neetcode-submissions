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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        auto dfs = [&](auto&&self, TreeNode* node) {
            if(!node) return 0;

            int left = self(self, node->left);
            int right = self(self, node->right);

            res = res && (abs(left-right) <= 1);

            return 1 + max(left, right);
        };

        dfs(dfs, root);

        return res;
        
    }
};
