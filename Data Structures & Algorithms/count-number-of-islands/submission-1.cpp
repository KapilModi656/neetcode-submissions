class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j){
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({i,j});
        visited[i][j]=true;
        int dx[4]={0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            pair<int,int> top = q.front();
            int x = top.first,y=top.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x+dx[k],ny = y+dy[k];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid[nx][ny]=='1'&&!visited[nx][ny]){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    count++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return count;
    }
};
