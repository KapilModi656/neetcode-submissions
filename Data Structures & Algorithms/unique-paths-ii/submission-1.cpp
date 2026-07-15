class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> prev(m,0);
        if(grid[0][0]==1) return 0;
        for(int i=0;i<n;i++){
            vector<int> curr(m,0);
            if(i==0) curr[0]=1;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) continue;
                if(i>0) curr[j]+=prev[j];
                if(j>0) curr[j]+=curr[j-1];
            }
            swap(curr,prev);
        }
        return prev[m-1];
    }
};