class Solution {
public:
    bool solve(vector<vector<int>>& adj,int node,vector<bool>& visited,vector<int>& parent){
        visited[node]=true;
        for(auto it:adj[node]){
            if(visited[it]&&parent[node]!=it) return false;
            if(!visited[it]){
                parent[it]=node;
                bool flag = solve(adj,it,visited,parent);
                if(!flag) return flag;
                parent[it]=-1;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        vector<int> parent(n,-1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]) {
                count++;
                bool flag = solve(adj,i,visited,parent);
                if(!flag) return false;
            }
        }
        if(count>1) return false;
        return true;
    }
};
