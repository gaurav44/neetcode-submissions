class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
     
        int lastEnd = intervals[0][1];
        int res = 0;
        for(int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start < lastEnd) {
                res++;
                lastEnd = min(end, lastEnd); 
            } else {
                lastEnd = end;
            }
        }
        
         return res;
    }
};
