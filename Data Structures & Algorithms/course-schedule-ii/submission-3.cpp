class Solution {
    enum class CourseStatus : int {
        kUnvisited,
        kExploring,
        kVisited
    };

    bool dfs(int course, vector<int>& res) {
        if(stat[course] == CourseStatus::kExploring)
        {
            res.clear();
            return false;
        } 

        if(stat[course] == CourseStatus::kVisited) return true;

        stat[course] = CourseStatus::kExploring;
        for(auto const preq: mp[course]) {
            if(!dfs(preq, res)) return false;
        }
        stat[course] = CourseStatus::kVisited;
        res.push_back(course);
        return true;
    }


    vector<CourseStatus> stat;
    unordered_map<int, vector<int>> mp;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        stat.resize(numCourses);

        std::fill(stat.begin(), stat.end(), CourseStatus::kUnvisited);

        for(auto const& preq : prerequisites) {
            mp[preq[0]].push_back(preq[1]);
        }
        
        vector<int> res;
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i, res)) return {};
        }

        return res;
    }
};
