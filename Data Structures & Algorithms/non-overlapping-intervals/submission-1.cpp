class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0],e=intervals[0][1];
        int count=0;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<e){
                count++;
                e=min(e,intervals[i][1]);
                continue;
            }
            else{
                e=intervals[i][1];
            }
        }
        return count;
    }
};
