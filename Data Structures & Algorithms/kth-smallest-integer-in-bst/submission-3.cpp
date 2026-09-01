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
    int kthSmallest(TreeNode* root, int k) {
        auto dfs = [&](auto&& self, TreeNode* node) -> TreeNode* {
            if(!node) return nullptr;

            auto left = self(self, node->left);
            if(left) return left;
            k--;
            
            if(k==0) return node;

            return self(self, node->right);
        };

        auto res = dfs(dfs, root);
        cerr << "hello from after res\n";
        return res->val;
    }
};
