class Solution {
public:

    bool dfs(vector<vector<int>>& adj,int node,vector<bool>& visited,vector<bool>& visit){
        int n=adj.size();
        visit[node]=true;
        visited[node]=true;
        for(auto it:adj[node]){
            if(visit[it]) return false;
            if(visited[it]) continue;
            bool flag=dfs(adj,it,visited,visit);
            if(!flag) return false;
        }
        visit[node]=false;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false),visit(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(!dfs(adj,i,visited,visit)) return false;
            }
        }
        return true;
    }
};
