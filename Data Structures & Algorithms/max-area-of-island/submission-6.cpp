class Solution {
public:
    int traverse(vector<vector<int>>& grid,int& i,
    int& j){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=0;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int area=1;
        while(!q.empty()){
            auto top = q.front();
            
            q.pop();
            int x=top.first,y=top.second;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==1){
                    area++;
                    grid[nx][ny]=0;
                    q.push({nx,ny});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=grid.size();
        int m=grid[0].size();
        int area=0;
      
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    area=max(area,traverse(grid,i,j));
                  
                }
            }
        }
        return area;
    }
};
