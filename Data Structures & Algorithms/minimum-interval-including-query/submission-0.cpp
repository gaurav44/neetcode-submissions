class Solution {
private:
    void queryInterval(const vector<vector<int>>& intervals, int query, vector<int>& output) {
        for(const auto interval: intervals) {
            if(query >= interval[0] && query <= interval[1]) {
                cout << query << " " << interval[0] << " " << interval[1] << "\n"; 
                output.push_back(interval[1] - interval[0] + 1);
                return;
            }   
        }
        output.push_back(-1);
    };
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return  a[1] - a[0] + 1 < b[1] - b[0] + 1;
        });

        // for(const auto interval: intervals) {
        //     cout << interval[0] << " " << interval[1] << "\n";
        // }

        vector<int> output;

        for(const auto query: queries) {
            queryInterval(intervals, query, output);
        }

        return output;
        
    }
};
