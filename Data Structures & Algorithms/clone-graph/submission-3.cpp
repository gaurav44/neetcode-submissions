/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        unordered_map<Node*, Node*> mp;

        auto dfs = [&](auto&& self, Node* node) -> Node* {
            if(!node) return nullptr;

            if(mp.contains(node)) return mp[node];

            auto new_node = new Node(node->val);
            mp[node] = new_node;

            for(const auto nei : node->neighbors) {
                new_node->neighbors.push_back(self(self, nei));
            }

            return new_node;
        };

        return dfs(dfs, node);
        
    }
};
