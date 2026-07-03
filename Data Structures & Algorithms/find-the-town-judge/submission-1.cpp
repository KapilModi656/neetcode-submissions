class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n+1);
        vector<vector<int>> adj(n+1);
        int m=trust.size();
        for(int i=0;i<m;i++){
            trusted[trust[i][1]]++;
            adj[trust[i][0]].push_back(trust[i][1]);
        }
        for(int i=1;i<=n;i++){
            if(trusted[i]==n-1&&adj[i].size()==0){
                return i;
            }
        }
        return -1;
    }
};