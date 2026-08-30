class Solution {
private:
    enum class Status {
        kVisited,
        kUnvisited,
        kExploring
    };

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<Status> stat(n, Status::kUnvisited);

        if(edges.size() != n - 1) return false;

        unordered_map<int, vector<int>> mp;

        for(const auto edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }

        auto dfs = [&] (auto&& self, int i, int parent) {
            if(stat[i] == Status::kExploring) return false;
            if(stat[i] == Status::kVisited) return true;

            stat[i] = Status::kExploring;
            for(const auto pre : mp[i]) {
                if(pre == parent) continue;
                if(!self(self, pre, i)) return false;
            }

            stat[i] = Status::kVisited;
            return true;
        };
        dfs(dfs, 0, -1);

        for(const auto st : stat) {
            if(st == Status::kUnvisited) return false;
        }

        return true;

    }
};
