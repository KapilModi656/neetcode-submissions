class Solution {
public:
    void traverse(vector<vector<char>>& grid,int& i,
    int& j,vector<vector<bool>>& visited){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int x=top.first,y=top.second;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]=='1'&&!visited[nx][ny]){
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    traverse(grid,i,j,visited);
                    count++;
                }
            }
        }
        return count;
    }
};
