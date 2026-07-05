class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0], v=times[i][1], w=times[i][2];
            adj[u].push_back({v,w});
        }
        set<pair<int,int>> st;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        dist[0]=0;
        st.insert({0,k});
        while(!st.empty()){
            auto top = *(st.begin());
            st.erase(st.begin());
            int node = top.second;
            int d = top.first;
            for(auto it:adj[node]){
                int child = it.first, w = it.second;
                if(d+w<dist[child]){
                    auto record = st.find({dist[child],child});
                    if(record!=st.end()){
                        st.erase(record);
                    }
                    dist[child] = d+w;
                    st.insert({dist[child],child});
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<=n;i++) maxi = max(maxi,dist[i]);
        if(maxi==INT_MAX) return -1;
        return maxi;
    }
};
