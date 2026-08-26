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

        auto dfs = [&](auto&& self, int inL, int inR) -> TreeNode* {
            if(inL > inR) return nullptr;

            int val = preorder[preIdx++];
            int mid = find(inorder.begin() + inL, inorder.end() + inR + 1, val) - inorder.begin();

            TreeNode* node = new TreeNode(val);
            node->left = self(self, inL, mid-1);
            node->right = self(self, mid+1, inR);

            return node;
        };

        return dfs(dfs, 0, inorder.size()-1);
    }
};
