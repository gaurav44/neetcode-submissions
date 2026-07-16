class Solution {

    enum class CourseStatus : int{
        kUnvisited,
        kExploring,
        kVisited
    };


    bool dfs(int course) {
        if(stat.at(course) == CourseStatus::kExploring) return false;

        if(stat.at(course) == CourseStatus::kVisited) return true;

        stat.at(course) = CourseStatus::kExploring;

        for(auto const preq : mp[course]) {
            if(!dfs(preq)) return false;
        }

        stat.at(course) = CourseStatus::kVisited;
        return true;
    }

    vector<CourseStatus> stat;

    unordered_map<int, vector<int>> mp;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        stat.resize(numCourses);

        for(int i = 0; i < numCourses; i++) {
            stat.at(i) = CourseStatus::kUnvisited;
        }

        for(auto const& preq: prerequisites) {
            mp[preq[0]].push_back(preq[1]);
        }

        bool res = true;
        for(int i = 0; i < numCourses; i++) {
            res = res && dfs(i);
        }

        return res;
    }
};
