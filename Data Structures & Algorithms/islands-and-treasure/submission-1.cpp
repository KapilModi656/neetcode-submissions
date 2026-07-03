class Solution {
public:
    void solve(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        q.push({i,j});
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int curr=0;
        visited[i][j]=true;
        while(!q.empty()){
            pair<int,int> top=q.front();
            q.pop();
            int x=top.first;
            int y=top.second;
           
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0&&ny>=0&&ny<m&&nx<n&&grid[nx][ny]!=-1&&!visited[nx][ny]){
                    visited[nx][ny]=true;
                    grid[nx][ny]=min(grid[nx][ny],grid[x][y]+1);
                    q.push({nx,ny});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    solve(grid,i,j);
                }
            }
        }
    }
};
