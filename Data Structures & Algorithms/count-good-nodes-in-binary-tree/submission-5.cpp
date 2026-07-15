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
    int dfs(TreeNode* node, int max_so_far) {
        if(!node) return 0;
        int count = 0;

        if(node->val >= max_so_far) {
            max_so_far = node->val;
            count = 1;
        }

        // max_so_far = max(node->val, max_so_far);
        count += dfs(node->left, max_so_far);
        count += dfs(node->right, max_so_far);

        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        // int max_so_far = 0;
        return dfs(root, root->val);
    }
};
