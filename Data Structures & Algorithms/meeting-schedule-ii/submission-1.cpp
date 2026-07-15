/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;

        for(auto const& i: intervals) {
            start.push_back(i.start);
            end.push_back(i.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int res = 0, count = 0, s = 0, e = 0;

        while(s < intervals.size()) {
            if(start[s] < end[e]) {
                s++;
                count++;
            } else {
                e++;
                count--;
            }
            res = max(res, count);
        }
        return res;
    }
};
