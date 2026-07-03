class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans = 0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=1){
                    continue;
                }
                for(int k=0;k<4;k++){
                    int nx = i+dx[k],ny=j+dy[k];
                    if(nx>=0&&ny>=0&&nx<n&&ny<m){
                        if(grid[nx][ny]==0) ans++;
                    }
                    else{
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};