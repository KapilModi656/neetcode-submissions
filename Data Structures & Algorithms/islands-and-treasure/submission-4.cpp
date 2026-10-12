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
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int i=top.first,j=top.second;
            for(int k=0;k<4;k++){
                int nx=dx[k]+i,ny=j+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]!=-1){
                    if(1+grid[i][j]<grid[nx][ny]){
                        grid[nx][ny]=1+grid[i][j];
                        q.push({nx,ny});
                    }
                }
            }
        
        }
    }
};
