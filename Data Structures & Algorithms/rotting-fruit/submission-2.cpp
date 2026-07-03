class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    dp[i][j]=0;
                }
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            auto top = q.front();
            int x = top.first , y = top.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x+dx[k],ny = y+dy[k];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid[nx][ny]==1){
                    if(dp[nx][ny]!=-1) continue;
                    dp[nx][ny] = 1+dp[x][y];
                    q.push({nx,ny});
                }
            }
        }
        int maxi = 0;
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1&&grid[i][j]==0) continue;
                maxi = max(dp[i][j],maxi);
                if(dp[i][j]==-1) flag=false;
            }
        }
        if(!flag) return -1;
        return maxi;
    }
};
