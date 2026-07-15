class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq;

        for(auto& pre: prerequisites) {
            prereq[pre[0]].push_back(pre[1]);
        }

        vector<int> output;
        unordered_set<int> cycle;
        unordered_set<int> visit;

        for(int course=0; course < numCourses; course++) {
            if(!dfs(course, prereq, visit, cycle, output)) return {};
        }

        return output;
    }

private:
    bool dfs(int course, const unordered_map<int, vector<int>>& prereq,
             unordered_set<int>& visit, unordered_set<int>& cycle,
             vector<int>& output) {
        
        if(cycle.count(course)) return false;

        if(visit.count(course)) return true;

        cycle.insert(course);
        if(prereq.count(course)) {
            for(int pre: prereq.at(course)) {
                if(!dfs(pre, prereq, visit, cycle, output)) return false;
            }
        }
        cycle.erase(course);
        visit.insert(course);
        output.push_back(course);
        return true;
    }
};
