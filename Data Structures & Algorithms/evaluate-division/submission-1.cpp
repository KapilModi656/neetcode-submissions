class Solution {
public:
    double dfs(map<string,map<string,double>> mp,map<string,bool> visited,string node,string target){
        if(node==target){
          
            return 1.00;
        }
        visited[node]=true;
        for(auto it:mp[node]){
            double ans=-1;
            if(!visited[it.first]){
                ans=dfs(mp,visited,it.first,target);
            }
            if(ans!=-1){
                return it.second*ans;
            }
        }
        return -1.00;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,map<string,double>> mp;
        
        vector<double> ans;
        int n=queries.size();
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]][equations[i][1]]=values[i];
            mp[equations[i][1]][equations[i][0]]=(1.00)/(values[i]);
            
        }
        
        for(int i=0;i<n;i++){
            map<string,bool> visited;
            if(mp.find(queries[i][0])==mp.end()||mp.find(queries[i][1])==mp.end()){
                ans.push_back(-1.00);
                continue;
            }
            double a=dfs(mp,visited,queries[i][0],queries[i][1]);
            ans.push_back(a);
        }
        return ans;
    }
};