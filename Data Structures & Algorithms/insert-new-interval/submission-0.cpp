class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int i=0;
        int s = newInterval[0],e=newInterval[1];
        for(;i<n;i++){
            int o_s = intervals[i][0],o_e = intervals[i][1];
            if(s>o_e){
                ans.push_back({o_s,o_e});
            }
            else{
                break;
            }
        }
        
        for(;i<n;i++){
            int o_s = intervals[i][0],o_e = intervals[i][1];
    
            if(o_s>e) break; 
            s=min(s,o_s);
            e=max(e,o_e);
        }
        ans.push_back({s,e});
        for(;i<n;i++) ans.push_back(intervals[i]);
        return ans;
    }
};
