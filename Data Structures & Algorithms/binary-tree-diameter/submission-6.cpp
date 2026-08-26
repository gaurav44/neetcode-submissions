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
    int diameterOfBinaryTree(TreeNode* root) {

        int maxDia = 0;
        auto dfs = [&] (auto&& self, TreeNode* node) {
            if(!node) return 0;

            int left = self(self, node->left);
            int right = self(self, node->right);

            maxDia = max(maxDia, left+right);

            return 1 + max(left, right);
        };

        dfs(dfs, root);
        return maxDia;
        
    }
};
