class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for(int node = 0; node < n; node++) {
            if (!visit[node]) {
                dfs(adj, visit, node);
                res++;
            }
        }
        return res;
    }

    void dfs(const vector<vector<int>>& adj, vector<bool>& visit, int node) {      
        visit[node] = true;
        for(int nei: adj[node]) {
            if(!visit[nei]) {
                dfs(adj, visit, nei);
            } 
        }
    }
};
