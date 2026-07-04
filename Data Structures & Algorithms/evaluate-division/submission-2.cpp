class Solution {
public:

    double solve(map<string,vector<string>>& adj,map<string,map<string,double>>& mp,string node,string target,map<string,bool>& visited){
        if(node==target) return 1.0;
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited.count(it)){
                double ans = solve(adj,mp,it,target,visited);
                if(ans!=-1.0) return ans*mp[node][it];
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& value, vector<vector<string>>& queries) {
        map<string,vector<string>> adj;
        map<string,map<string,double>> mp;
        for(int i=0;i<equations.size();i++){
            string u = equations[i][0],v=equations[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            mp[u][v] = value[i];
            mp[v][u] = 1.0/value[i];
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            string src = queries[i][0],dist=queries[i][1];
            if(!mp.count(queries[i][0])||!mp.count(queries[i][1])){
                ans.push_back(-1.0);
                continue;
            }
            else if(src==dist){
                ans.push_back(1.0);
                continue;
            }
            else{
                map<string,bool> visited;
                ans.push_back(solve(adj,mp,src,dist,visited));
            }

        }
        return ans;

    }
};