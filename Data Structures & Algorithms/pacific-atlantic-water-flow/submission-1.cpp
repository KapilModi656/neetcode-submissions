class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> ispacific(n,vector<bool>(m,0));
        vector<vector<bool>> isatlantic(n,vector<bool>(m,0));
        
        queue<pair<int,int>> q1,q2;
        for(int i=0;i<m;i++){
            ispacific[0][i]=true;
            q1.push({0,i});
            q2.push({n-1,i});
            isatlantic[n-1][i]=true;
        }
        for(int i=0;i<n;i++){
            ispacific[i][0]=true;
            isatlantic[i][m-1]=true;
            q1.push({i,0});
            q2.push({i,m-1});
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q1.empty()){
            auto top=q1.front();
            q1.pop();
            int x=top.first;
            int y=top.second;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<n&&nx>=0&&ny<m&&ny>=0){
                    if(heights[nx][ny]>=heights[x][y]&&!ispacific[nx][ny]){
                        ispacific[nx][ny]=true;
                        q1.push({nx,ny});
                    }
                }
            }
        }
        while(!q2.empty()){
            auto top=q2.front();
            q2.pop();
            int x=top.first;
            int y=top.second;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<n&&nx>=0&&ny<m&&ny>=0){
                    if(heights[nx][ny]>=heights[x][y]&&!isatlantic[nx][ny]){
                        isatlantic[nx][ny]=true;
                        q2.push({nx,ny});
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ispacific[i][j]&&isatlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};
