class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visit,int i,int j){
        visit[i][j]=true;
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx<n&&nx>=0&&ny<m&&ny>=0&&grid[nx][ny]=='1'){
                if(!visit[nx][ny]) dfs(grid,visit,nx,ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visit(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!visit[i][j]){
                    dfs(grid,visit,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
