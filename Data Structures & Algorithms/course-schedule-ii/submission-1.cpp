class Solution {
public:
    bool solve(vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& path,int node){
        visited[node]=true;
        path[node]=true;
        
        for(auto it:adj[node]){
            if(!visited[it]){
                if(solve(adj,visited,path,it)){
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
    void topo(vector<vector<int>>& adj,vector<bool>& visited,stack<int>& ans,int node){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                topo(adj,visited,ans,it);
            }
        }
        ans.push(node);
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<bool> visited(n,false);
        vector<bool> path(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool flag=solve(adj,visited,path,i);
                if(flag){
                    return {};
                }
            }
        }
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                topo(adj,visited,st,i);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
