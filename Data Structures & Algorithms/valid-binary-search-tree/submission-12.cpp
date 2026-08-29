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
    bool isValidBST(TreeNode* root) {

        auto dfs = [&](auto&& self, TreeNode* node, long long lower, long long upper) {
            if(!node) return true;

            if(static_cast<long long>(node->val) <= lower || static_cast<long long>(node->val) >= upper) {
                cout << "triggered false " << node->val << " " << lower << " " << upper << "\n";
                return false;
            } 

            // left subtree && right subtree
            return self(self, node->left, lower, node->val) &&
                   self(self, node->right, node->val, upper);
        };

        return dfs(dfs, root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
        
    }
};
