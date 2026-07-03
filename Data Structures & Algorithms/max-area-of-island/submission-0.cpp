class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j){
        visited[i][j]=true;
        int n=grid.size();
        int m=grid[0].size();
        int ans=1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            pair<int,int> top=q.front();
            q.pop();
            int x=top.first;
            int y=top.second;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(visited[nx][ny]!=true&&grid[nx][ny]==1){
                        ans++;
                        visited[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
            
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]==1){
                    maxi=max(maxi,solve(grid,visited,i,j));
                }
            }
        }
        return maxi;
    }
};
