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
        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i = 0;
        int j = 0;
        int cur = 0;
        int re = 0;
        while(i<start.size()){
            if(start[i] < end[j]){
                cur++;
                i++;
            }
            else{
                cur--;
                j++;
            }
            re = max(re, cur);
        }
        return re;
    }
};
