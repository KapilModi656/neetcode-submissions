class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        pq.push({0,src});
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        vector<int> steps(n,0);
        while(!pq.empty()){
            auto top = pq.front();
            pq.pop();
            int node = top.second;
            int cost = top.first;
            if(cost>dist[node]) continue;
            for(auto it:adj[node]){
                if(1+steps[node]>k&&it.first!=dst){
                    continue;
                }
                if(dist[it.first]>cost+it.second){
                    dist[it.first] = cost+it.second;
                    if(it.first==dst){
                        steps[it.first] = steps[node];
                    }
                    else steps[it.first] = 1+steps[node];
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};
