class Solution {
public:
    void dfs(map<string,multiset<string>>& adj,string s,vector<string>& ans){
      
        while(!adj[s].empty()){
            auto it = adj[s].begin();
            auto next = *it;
            adj[s].erase(it);
            dfs(adj,next,ans);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       
        map<string,multiset<string>> adj;
        vector<string> ans;
        for(auto t:tickets){
            adj[t[0]].insert(t[1]);
        }
     
        dfs(adj,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
