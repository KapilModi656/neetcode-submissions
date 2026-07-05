class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> dist(points.size(),INT_MAX);
        dist[0]=0;
        vector<bool> visited(points.size(),false);
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int d = top.first;
            int i = top.second;
            visited[i]=true;
            if(d>dist[i]) continue;
            for(int j=0;j<points.size();j++){
                if(j==i) continue;
                if(visited[j]) continue;
                int w = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                if(w<dist[j]){
                    dist[j]=w;
                    pq.push({w,j});
                }
            }
        }
        int sumi=0;
        for(int i=0;i<points.size();i++) sumi+=dist[i];
        return sumi;

    }
};
