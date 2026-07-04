class Solution {
public:
    void solve(map<string,vector<string>>& mp,vector<string>& ans, string node,map<string,bool>& visited){
        visited[node]=true;
        ans.push_back(node);
        for(auto it:mp[node]){
            if(!visited.count(it)){
                solve(mp,ans,it,visited);
            }
        }
        
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,vector<string>> mp;
        map<string,string> name;
        for(auto it:accounts){
            name[it[1]] = it[0];
            if(!mp.count(it[1])) mp[it[1]]={};
            for(int i=2;i<it.size();i++){
                name[it[i]] = it[0];
                mp[it[1]].push_back(it[i]);
                mp[it[i]].push_back(it[1]);
            }
        }
        map<string,bool> visited;
        vector<vector<string>> answer;
        for(auto it:mp){
            if(!visited.count(it.first)){
                vector<string> ans;
                ans.push_back(name[it.first]);
                solve(mp,ans,it.first,visited);
                sort(ans.begin()+1,ans.end());
                answer.push_back(ans);
            }
        }
        return answer;
    }
};