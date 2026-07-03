class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j){
        int count=1;
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        visited[i][j]=true;
        q.push({i,j});
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            auto top=q.front();
            int x=top.first,y=top.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid[nx][ny]==1&&!visited[nx][ny]){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                    count++;
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!visited[i][j]){
                    ans = max(ans,bfs(grid,visited,i,j));
                }
            }
        }
        return ans;
    }
};
