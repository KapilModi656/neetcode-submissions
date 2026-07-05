class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({0,0});
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = grid[0][0];
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i = top.first;
            int j = top.second;
            for(int k=0;k<4;k++){
                int nx = i+dx[k],ny = j+dy[k];
                if(nx>=0&&ny>=0&&nx<n&&ny<m){
                    if(max(dist[i][j],grid[nx][ny])<dist[nx][ny]){
                        dist[nx][ny] = max(dist[i][j],grid[nx][ny]);
                        q.push({nx,ny});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
