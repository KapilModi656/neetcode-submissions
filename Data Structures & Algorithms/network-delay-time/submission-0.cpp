class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto e:times){
            adj[e[0]].push_back({e[1],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int d=t.first;
            int node=t.second;
            if(d>dist[node]) continue;
            for(auto it:adj[node]){
                if(it.second+d<dist[it.first]){
                    dist[it.first]=it.second+d;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int maxi=-1;
        for(int i=1;i<=n;i++){
            if(i==k) continue;
            maxi=max(maxi,dist[i]);
        }
        if(maxi==INT_MAX) return -1;
        return maxi;
    }
};
