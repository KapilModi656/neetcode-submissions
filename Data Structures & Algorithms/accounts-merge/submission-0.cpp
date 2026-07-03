class Solution {
public:
    void dfs(map<string,vector<string>>& mp,map<string,bool>& visited,vector<string>& temp,string s){
        visited[s]=true;
        temp.push_back(s);
        for(auto it:mp[s]){
            if(!visited[it]){
                dfs(mp,visited,temp,it);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,vector<string>> mp;
        map<string,string> mp2;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                mp2[accounts[i][j]]=accounts[i][0];
                if(j!=1){
                    mp[accounts[i][j]].push_back(accounts[i][1]);
                    mp[accounts[i][1]].push_back(accounts[i][j]);
                }
            }
            if(mp.find(accounts[i][1])==mp.end()){
                mp[accounts[i][1]]={};
            }
        }
        map<string,bool> visited;
        vector<vector<string>> ans;
        for(auto it:mp){
            if(!visited[it.first]){
                vector<string> temp;
                temp.push_back(mp2[it.first]);
                dfs(mp,visited,temp,it.first);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};