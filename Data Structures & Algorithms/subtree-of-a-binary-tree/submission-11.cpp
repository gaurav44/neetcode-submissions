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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        auto isSameTree = [&](auto&& self, TreeNode* p, TreeNode* q) -> bool{
            if(!p && !q) return true;

            if(!p && q || p && !q || p->val != q->val) return false;

            return self(self, p->left, q->left) && self(self, p->right, q->right);
        };

        auto dfs = [&](auto&& self, TreeNode* node) -> bool {
            if(!node) return false;

            if(node->val == subRoot->val && 
               isSameTree(isSameTree, node, subRoot)) return true;
            
            return self(self, node->left) || self(self, node->right);
        };

        
        return dfs(dfs, root);
    }
};
