class Solution {
public:
    bool solve(vector<vector<int>>& adj,vector<bool>& visited,int node,vector<int>& parent){
        visited[node]=true;
        for(auto it:adj[node]){
            if(parent[node]==it) continue;
            parent[it]=node;
            if(visited[it]){
                return true;
            }
            if(solve(adj,visited,it,parent)){
                return true;
            }
        }
     
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        vector<int> parent(n,-1);
        bool flag=solve(adj,visited,0,parent);
        if(flag) return false;
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};
