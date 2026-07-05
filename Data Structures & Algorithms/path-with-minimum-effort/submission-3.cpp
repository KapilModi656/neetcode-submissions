class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m = heights[0].size();
        set<pair<int,pair<int,int>>> pq;
        pq.insert({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!pq.empty()){
            auto top = *pq.begin();
            pq.erase(pq.begin());
            int d = top.first, i = top.second.first, j=top.second.second;
            for(int k=0;k<4;k++){
                int nx=i+dx[k],ny=j+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    int w = abs(heights[i][j]-heights[nx][ny]);
                    if(max(w,dist[i][j])<dist[nx][ny]){
                        auto record = pq.find({dist[nx][ny],{nx,ny}});
                        if(record!=pq.end()){
                            pq.erase(record);
                        }
                        dist[nx][ny] = max(w,dist[i][j]);
                        pq.insert({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};