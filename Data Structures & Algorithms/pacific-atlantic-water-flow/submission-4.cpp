class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,false)),
        atlantic(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            pacific[i][0]=true;
            q.push({i,0});
          
        }
        for(int j=1;j<m;j++){
            pacific[0][j]=true;
            q.push({0,j});
            
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            auto top=q.front();
            int i=top.first,j=top.second;
            q.pop();
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x>=0&&x<n&&y>=0&&y<m&&((heights[i][j]<heights[x][y])||(heights[i][j]==heights[x][y]&&pacific[x][y]!=true))){
                    pacific[x][y]=true;
                    q.push({x,y});
                }
            }
        }
        for(int i=0;i<n;i++){
            atlantic[i][m-1]=true;
            q.push({i,m-1});
        }
        for(int j=0;j<m-1;j++){
            atlantic[n-1][j]=true;
            q.push({n-1,j});
        }
        while(!q.empty()){
            auto top=q.front();
            int i=top.first,j=top.second;
            q.pop();
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x>=0&&x<n&&y>=0&&y<m&&((heights[i][j]<heights[x][y])||(heights[i][j]==heights[x][y]&&atlantic[x][y]!=true))){
                    atlantic[x][y]=true;
                    q.push({x,y});
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]&&atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
