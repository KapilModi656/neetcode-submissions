class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
      
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
         
        }
        vector<vector<bool>> isReachable(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++){
            queue<int> q;
            q.push(i);
            isReachable[i][i]=true;
            while(!q.empty()){
                auto top = q.front();
                q.pop();
                
                for(auto it:adj[top]){
                    if(isReachable[i][it]) continue;
                    isReachable[i][it]=true;
                    q.push(it);
                }
            }
        }
        vector<bool> ans;
        
        
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            ans.push_back(isReachable[u][v]);
        }
        return ans;
    }
};