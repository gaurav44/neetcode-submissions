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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& interval1, auto& interval2) {
            return interval1.start < interval2.start;
        });

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }
        return true;
    }
};
