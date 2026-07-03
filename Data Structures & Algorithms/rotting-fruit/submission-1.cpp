class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
       
  
        while(!q.empty()){
            pair<int,int> top=q.front();
            q.pop();
            int x=top.first;
            int y=top.second;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<n&&nx>=0&&ny<m&&ny>=0&&grid[nx][ny]==1){
                    if(ans[nx][ny]>ans[x][y]+1){
                        ans[nx][ny]=ans[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }

        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxi=max(maxi,ans[i][j]);
                }
            }
        }
        if(maxi==INT_MAX) return -1;
        return maxi;

    }
};
