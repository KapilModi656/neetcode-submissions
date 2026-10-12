class Solution {
public:
    bool dfs(vector<vector<int>>& adj,int node,vector<bool>& cyclic,vector<bool>& visited,vector<int>& parent,int& start){
        visited[node]=true;
        for(auto it:adj[node]){
            if(it==parent[node]) continue;
            if(visited[it]){
                cyclic[node]=true;
                start=it;
                return true;
            }
            parent[it]=node;
            if(dfs(adj,it,cyclic,visited,parent,start)){
                cyclic[node]=true;
                if(start==node) return false;
                return true;
            }
        }
        return false;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> inorder(n+1,0);
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            inorder[edges[i][0]]++;
            inorder[edges[i][1]]++;
        }
        vector<bool> visited(n+1,false),cyclic(n+1,false);
        int start=-1;
        vector<int> parent(n+1,0);
        dfs(adj,1,cyclic,visited,parent,start);
        for(int i=n-1;i>=0;i--){
            if(cyclic[edges[i][0]]&&cyclic[edges[i][1]]) return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};
