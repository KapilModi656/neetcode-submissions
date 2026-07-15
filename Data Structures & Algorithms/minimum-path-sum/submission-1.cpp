class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> prev(m,INT_MAX);
        for(int i=0;i<n;i++){
            vector<int> curr(m,INT_MAX);
            if(i==0) curr[0]=0;
            for(int j=0;j<m;j++){
                if(i>0) curr[j] = min(curr[j],prev[j]);
                if(j>0) curr[j] = min(curr[j],curr[j-1]);
                curr[j]+=grid[i][j];
            }
            swap(prev,curr);
        }
        return prev[m-1];
    }
};