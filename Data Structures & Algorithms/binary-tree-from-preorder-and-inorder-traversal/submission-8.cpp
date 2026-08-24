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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;

        auto dfs = [&](auto&& self, int left, int right) -> TreeNode* {
            if (left > right) return nullptr;

            int val = preorder[preIdx++];
            int mid = find(inorder.begin() + left,
                        inorder.begin() + right + 1,
                        val) - inorder.begin();

            TreeNode* node = new TreeNode(val);

            node->left = self(self, left, mid - 1);
            node->right = self(self, mid + 1, right);

            return node;
        };

        return dfs(dfs, 0, inorder.size() - 1);
    }
};
