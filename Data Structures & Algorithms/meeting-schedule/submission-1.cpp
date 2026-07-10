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
        int count=0;
        int n=intervals.size();
        if(n==0) return true;
        sort(intervals.begin(),intervals.end(),[](const Interval a,const Interval b){
            return a.start<b.start;
        });
        int e = intervals[0].end;
        for(int i=1;i<n;i++){
            if(intervals[i].start<e){
                count++;
                e=min(e,intervals[i].end);
            }
            else{
                e=intervals[i].end;
            }
        }
        if(count) return false;
        return true;
    }
};
