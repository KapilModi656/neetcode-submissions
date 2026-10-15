class Solution {
public:
    void dfs(map<string,queue<string>>& adj,string node,vector<string>& ans){
        while(!adj[node].empty()){
            string top = adj[node].front();
            adj[node].pop();
            dfs(adj,top,ans);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end());
       
        map<string,queue<string>> adj;
        for(int i=0;i<tickets.size();i++){
            adj[tickets[i][0]].push(tickets[i][1]);
        }
        vector<string> ans;
        dfs(adj,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
