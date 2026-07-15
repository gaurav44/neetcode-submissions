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
    vector<int> bfs(queue<TreeNode*>& q) {
        vector<int> ret;
        queue<TreeNode*> tmp;
        while(!q.empty()) {
            ret.push_back(q.front()->val);
            if(q.front()->left) tmp.push(q.front()->left);
            if(q.front()->right) tmp.push(q.front()->right);
            q.pop();
        }
        q = tmp;
        return ret;
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;
        while(!q.empty()) {
            int n = q.size();
            vector<int> level_vec;
            for(int i = 0; i < n; i++) {
                level_vec.push_back(q.front()->val);
                auto node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(level_vec);
        }
        return res;
    }
};
