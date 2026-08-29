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
    int goodNodes(TreeNode* root) {
        int maxSoFar = root->val;
        int count = 0;
        auto dfs = [&](auto&& self, TreeNode* node, int maxSoFar) {
            if(!node) return;
            if(node->val >= maxSoFar) {
                count++;
            }

            maxSoFar = max(maxSoFar, node->val);

            self(self, node->left, maxSoFar);
            self(self, node->right, maxSoFar);
        };
        dfs(dfs, root, maxSoFar);
        return count;
        
    }
};
