class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dist(n,vector<int>(m,0));
        int maxi = 1;
        queue<pair<int,pair<int,int>>> q;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool flag=true;
                for(int k=0;k<4;k++){
                    int nx = i+dx[k],ny=j+dy[k];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m){
                        if(matrix[nx][ny]<matrix[i][j]){
                            flag=false;
                        }
                    }
                }
                if(flag){
                    dist[i][j]=1;
                    q.push({1,{i,j}});
                }
            }
        }
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i=top.second.first,j=top.second.second,d=top.first;
            if(d<dist[i][j]) continue;
            for(int k=0;k<4;k++){
                int nx = i+dx[k],ny=j+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(matrix[nx][ny]>matrix[i][j]){
                        if(dist[nx][ny]<d+1){
                            q.push({d+1,{nx,ny}});
                            dist[nx][ny]=d+1;
                        }
                        maxi = max(maxi,dist[nx][ny]);
                    }
                }
            }
        }
        return maxi;
    }
};
