class Solution {
public:
    bool solve(vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& dfsvisited,int i){
        dfsvisited[i]=true;
        visited[i]=true;
        for(auto it:adj[i]){
            if(dfsvisited[it]){
                return false;
            }
            else if(!visited[it]){
                bool flag = solve(adj,visited,dfsvisited,it);
                if(!flag) return false;
            }
        }
        dfsvisited[i]=false;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int m = edges.size();
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        vector<bool> dfsvisited(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool flag = solve(adj,visited,dfsvisited,i);
                if(!flag) return false;
            }
        }
        return true;

    }
};
