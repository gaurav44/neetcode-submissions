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

        auto isValid = [&](auto&& self, TreeNode* node, int low, int high) {
            if(!node) return true;

            if(node->val <= low || node->val >= high) return false;

            return self(self, node->left, low, node->val) && 
                   self(self, node->right, node->val, high);
        };

        return isValid(isValid, root, numeric_limits<int>::min(), numeric_limits<int>::max());
        
    }
};
