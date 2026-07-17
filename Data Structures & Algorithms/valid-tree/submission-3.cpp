class Solution {
    bool dfs(int node, int parent) {
        if (stat.at(node) == 1) return false;

        stat.at(node) = 1;

        for(const auto i: mp[node]) {
            if(i == parent) continue;
            if(!dfs(i, node)) return false;
        }

        return true;
    } 

    vector<int> stat;
    unordered_map<int, vector<int>> mp;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int r = edges.size();

        for(int i = 0; i < n; i++) {
            stat.push_back(0);
        }

        for(int i = 0; i < r; i++) {
            mp[edges.at(i).at(0)].push_back(edges.at(i).at(1));
            mp[edges.at(i).at(1)].push_back(edges.at(i).at(0));
        }

        if(!dfs(0, -1)) return false;
        
        auto check = std::find(stat.begin(), stat.end(), 0);

        if(check != stat.end()) return false;

        return true;
    }
};
