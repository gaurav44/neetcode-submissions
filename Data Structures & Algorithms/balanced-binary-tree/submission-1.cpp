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

        auto isSubBalanced = [&](auto&& self, TreeNode* node) -> int {
            if(!node) return 0;

            int left = 1 + self(self, node->left);
            int right = 1 + self(self, node->right);

            cout << boolalpha << node->val << " "
                 << left << " " << right << " " << (abs(left - right) < 2) << "\n";
            
            res = res && (abs(left - right) < 2);

            return max(left, right);
        };
       isSubBalanced(isSubBalanced, root);
       return res;
    }
};
