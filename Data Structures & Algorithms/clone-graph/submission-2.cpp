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
        if(!node) return node;
        unordered_map<Node*, Node*> visited;

        auto dfs = [&](auto&& self, Node* curr) -> Node* {
            if(visited.contains(curr)) return visited[curr];
            Node* new_curr = new Node();
            new_curr->val = curr->val;
            visited[curr] = new_curr;
            cout << new_curr->val << "\n";

            for(const auto nei: curr->neighbors) {
                cout << "Visiting... " << nei->val << "\n";
                new_curr->neighbors.push_back(self(self, nei));
            }
            return new_curr;
        };
        
        return dfs(dfs, node);
    }
};
