class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            auto top = q.front();
            int x = top.first,y=top.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(grid[nx][ny]!=INT_MAX) continue;
                    grid[nx][ny] = 1+grid[x][y];
                    q.push({nx,ny});
                }
            }
        }
        

    }
};
