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
private:
    bool dfs(TreeNode* node, long low, long high) {
        if(!node) return true;

        if(node->val >= high || node->val <= low) return false;

        return dfs(node->left, low, node->val) && 
               dfs(node->right, node->val, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    }
};
