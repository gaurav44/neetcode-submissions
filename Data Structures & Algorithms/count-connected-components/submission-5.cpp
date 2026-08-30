class Solution {
    enum class Status {
        kVisited,
        kUnvisited
    };

public:
    int countComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> mp;

        for(const auto edge: edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }

        vector<Status> stat(n, Status::kUnvisited);


        auto dfs = [&] (auto&& self, int i, int parent) -> void {
            if(stat[i] == Status::kVisited) return;
            stat[i] = Status::kVisited;
            for(const auto nei : mp[i]) {
                if(nei == parent) continue;

                self(self, nei, i);
            }
        };  

        int count = 0;

        for(int i = 0; i < n; i++) {
            if(stat[i] == Status::kUnvisited) {
                count++;
                dfs(dfs, i, -1);
            }
        }
        
        return count;

    }
};
