class Solution {
public:
    bool check(vector<vector<int>>& adj,int node,int target,vector<vector<int>>& dp){
  
        if(node==target){
            return true;
        }
        if(dp[node][target]!=-1){
            if(dp[node][target]==0) return false;
            else return true;
        }
        for(auto it:adj[node]){
            if(check(adj,it,target,dp)){
                dp[node][target]= 1;
                break;
            }
        }
        if(dp[node][target]==-1) dp[node][target]=0;
        return dp[node][target];
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> adj(n);
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<pre.size();i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<bool> ans;
        for(int i=0;i<q.size();i++){
            int node=q[i][0];
            int target=q[i][1];
        
            ans.push_back(check(adj,node,target,dp));
        }
        return ans;
    }
};