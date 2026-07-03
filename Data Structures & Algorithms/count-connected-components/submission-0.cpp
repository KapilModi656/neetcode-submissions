class Solution {
public:
    void dfs(vector<vector<int>>& adj,int node,vector<bool>& visited){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(adj,it,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};
