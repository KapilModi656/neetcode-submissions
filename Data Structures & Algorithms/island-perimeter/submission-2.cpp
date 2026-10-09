class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=true;
                    break;
                }
            }
        }
        
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int i=t.first;
            int j=t.second;
            int count=4;
            for(int k=0;k<4;k++){
                int x=dx[k]+i;
                int y=dy[k]+j;
                if(x>=0&&y>=0&&x<n&&y<m&&grid[x][y]==1){
                    count--;
                    if(!visited[x][y]){
                        visited[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
            ans+=count;
        }
        return ans;
    }
};