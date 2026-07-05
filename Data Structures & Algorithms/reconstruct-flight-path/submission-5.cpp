class Solution {
public:
    void dfs(map<string,priority_queue<string, vector<string>, greater<string>>>& adj,string node,vector<string>& ans){
        
        while(!adj[node].empty()){
            string node2 = adj[node].top();
            adj[node].pop();
            dfs(adj,node2,ans);
        }
        ans.push_back(node);
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        map<string,priority_queue<string, vector<string>, greater<string>>> adj;
        for(int i=0;i<tickets.size();i++){
            adj[tickets[i][0]].push(tickets[i][1]);
        }
        
        vector<string> ans;
        
        dfs(adj,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
