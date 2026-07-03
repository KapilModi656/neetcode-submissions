class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
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
     
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int i=front.first;
            int j=front.second;
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx<n&&nx>=0&&ny<m&&ny>=0&&grid[nx][ny]==1){
                    if(!visited[nx][ny]){
                        q.push({nx,ny});
                        visited[nx][ny]=true;
                    } 
                    
                }
                else{
                    ans++;
                }
            }
        
        }
        return ans;
    }
};