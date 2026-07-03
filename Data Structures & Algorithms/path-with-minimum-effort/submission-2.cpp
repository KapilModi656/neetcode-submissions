class Solution {
public:
    int solve(vector<vector<int>>& heights){
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            int curr=front[0];
            int i=front[1];
            int j=front[2];
            if(i==n-1&&j==m-1) return curr;
            if(curr>dist[i][j]) continue;
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0&&ny>=0&&nx<n&&ny<m){
                    int eff = max(curr,abs(heights[i][j]-heights[nx][ny]));
                    if(eff<dist[nx][ny]){
                        dist[nx][ny]=eff;
                        pq.push({eff,nx,ny});
                    }
                    
                }
            
            }
        }
        return 0;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        return solve(heights);
    }
};