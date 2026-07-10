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
        int n=intervals.size();
        if(n==0) return 0;
        priority_queue<int,vector<int>,greater<int>> mini;
      
        sort(intervals.begin(),intervals.end(),[](const Interval a,const Interval b){
            return a.start<b.start;
        });
        mini.push(intervals[0].end);
        for(int i=1;i<n;i++){
            
            int top = mini.top();
            if(top<=intervals[i].start){
                mini.pop();
                mini.push(intervals[i].end);
            }
            else{
                
                mini.push(intervals[i].end);
            }
        }
        return mini.size();

    }
};
