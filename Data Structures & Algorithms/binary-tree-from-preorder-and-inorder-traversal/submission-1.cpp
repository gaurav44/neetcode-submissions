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
    using It = vector<int>::iterator;

    TreeNode* build(It preL, It preR, It inL, It inR) {
        if (preL == preR) return nullptr;

        int rootVal = *preL;
        TreeNode* root = new TreeNode(rootVal);

        It rootIn = std::find(inL, inR, rootVal);

        auto leftSize = std::distance(inL, rootIn);

        root->left = build(
            std::next(preL),
            std::next(preL, 1 + leftSize),
            inL,
            rootIn
        );

        root->right = build(
            std::next(preL, 1 + leftSize),
            preR,
            std::next(rootIn),
            inR
        );

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(
            preorder.begin(), preorder.end(),
            inorder.begin(), inorder.end()
        );
    }
};
