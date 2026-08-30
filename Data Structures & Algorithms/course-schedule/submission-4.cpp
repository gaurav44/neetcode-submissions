class Solution {
private:
    enum class CourseStatus {
        kVisited,
        kExploring,
        kUnvisited
    };

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<CourseStatus> stat(numCourses, CourseStatus::kUnvisited);
        unordered_map<int, vector<int>> mp;

        for(const auto pre: prerequisites) {
            mp[pre[0]].push_back(pre[1]);
        }
        
        auto dfs = [&](auto&& self, int course) {
            if(stat.at(course) == CourseStatus::kExploring) return false;
            if(stat.at(course) == CourseStatus::kVisited) return true;

            stat.at(course) = CourseStatus::kExploring;

            for(const auto pre : mp[course]) {
                if(!self(self, pre)) return false;
            }

            stat.at(course) = CourseStatus::kVisited;
            return true;
        };

        bool res = true;

        for(int i = 0; i < numCourses; i++) {
            res = res && dfs(dfs, i);
        }

        return res;
    }
};
