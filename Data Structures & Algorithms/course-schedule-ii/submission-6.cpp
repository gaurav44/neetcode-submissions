class Solution {
    enum class CourseStatus {
        kVisited,
        kUnvisited,
        kExploring
    };
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<CourseStatus> stat(numCourses, CourseStatus::kUnvisited);
        unordered_map<int, vector<int>> mp;
        vector<int> res;

        for(const auto pre: prerequisites) {
            mp[pre[0]].push_back(pre[1]);
        }

        auto dfs = [&] (auto&& self, int course) {
            if(stat.at(course) == CourseStatus::kExploring) {
                return false;
            } 
            if(stat.at(course) == CourseStatus::kVisited) return true;

            stat.at(course) = CourseStatus::kExploring;

            for(const auto pre: mp[course]) {
                if(!self(self, pre)) return false;
            }

            stat.at(course) = CourseStatus::kVisited;

            res.push_back(course);

            return true;
        };

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(dfs, i)) return {};
        }
        return res;
    }
};
