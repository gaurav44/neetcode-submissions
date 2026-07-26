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
        vector<int> start;
        vector<int> end;
        for(const auto interval: intervals) {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i_start = 0;
        int i_end = 0;
        int count = 0;
        int maxCount = 0;
        while(i_start < start.size()) {
            if(start[i_start] < end[i_end]) {
                count++;
                i_start++;
                maxCount = max(maxCount, count);
            } else {
                count--;
                i_end++;
            }
        }
        return maxCount;
        
    }
};
