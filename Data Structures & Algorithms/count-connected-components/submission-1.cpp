class Solution {
    vector<int> stat;
    unordered_map<int, vector<int>> mp;

    void dfs(int node) {
        if(stat[node] == 1) return;

        stat[node] = 1;

        for(auto const neigh: mp[node]) {
            dfs(neigh);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) {
            stat.push_back(0);
        }

        for(int i = 0; i < edges.size(); i++) {
            mp[edges.at(i).at(0)].push_back(edges.at(i).at(1));
            mp[edges.at(i).at(1)].push_back(edges.at(i).at(0));
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            if(stat[i] == 0) {
                res++;
                dfs(i);
            } 
        }

        return res;
    }
};
