class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> isAtlantic(n,vector<bool>(m,false)),
        isPacific(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            q.push({i,0});
            isPacific[i][0]=true;
        }
        for(int i=1;i<m;i++){
            q.push({0,i});
            isPacific[0][i]=true;
        }
        int dx[4]={0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!q.empty()){
            auto top = q.front();
            int x=top.first,y=top.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&heights[nx][ny]>=heights[x][y]&&!isPacific[nx][ny]){
                    isPacific[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<n;i++){
            q.push({i,m-1});
            isAtlantic[i][m-1]=true;
        }
        for(int i=0;i<m-1;i++){
            q.push({n-1,i});
            isAtlantic[n-1][i]=true;
        }
        
        while(!q.empty()){
            auto top = q.front();
            int x=top.first,y=top.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&heights[nx][ny]>=heights[x][y]&&!isAtlantic[nx][ny]){
                    isAtlantic[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isPacific[i][j]&&isAtlantic[i][j]){
                    arr.push_back({i,j});
                }
            }
        }
        return arr;
    }
};
