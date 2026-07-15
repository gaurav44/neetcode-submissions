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
private:
    unordered_map<Node*, Node*> visited;

    Node* clone(Node* node) {
        if(visited.contains(node)) return visited[node];

        auto cl = new Node(node->val);
        visited[node] = cl;

        for(const auto& neigh: node->neighbors) {
            cl->neighbors.push_back(clone(neigh));
        } 

        return cl;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;

        return clone(node);
    }
};
