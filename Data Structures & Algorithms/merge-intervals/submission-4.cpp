class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int lastEnd = output.back()[1];
            // cout << start << " " << lastEnd << " " << end <<"\n";
            if(start <= lastEnd) {
                output.back()[1] = max(end, lastEnd);
            } else {
                output.push_back({start,end});
            }
        }
        return output;
    }
};
