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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int levelSize = q.size();
            for(int l = 0; l < levelSize; l++) {
                auto temp = q.front(); 
                q.pop();

                if(l == levelSize - 1) {
                    res.push_back(temp->val);
                }

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }

        return res;
        
    }
};
