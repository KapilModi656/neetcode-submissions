class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        vector<bool> visited(n,false);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1) q.push(i);
        }
        int rem=n;
        while(rem>2){
            int size=q.size();
            rem=rem-size;
            for(int i=0;i<size;i++){
                int lf=q.front();
                q.pop();
                for(int neigh:adj[lf]){
                    degree[neigh]--;
                    if(degree[neigh]==1) q.push(neigh);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};