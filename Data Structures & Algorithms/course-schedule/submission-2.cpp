class Solution {
public:
    bool dfs(vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& path,int node){

        visited[node]=true;
        path[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(adj,visited,path,it)){
                    return true;
                }
            }
            if(path[it]){
                return true;
            }
        }
        path[node]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<bool> visited(n,false);
        vector<bool> path(n,false);
    
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool flag=dfs(adj,visited,path,i);
                if(flag) return false;
            }
            
            
        }
        return true;
    }
};
