class Solution {
public:
    int findJudge(int n, vector<vector<int>>& edge) {
        vector<int> trusted(n,1);
        vector<int> trusts(n,0);
        for(int i=0;i<edge.size();i++){
            trusted[edge[i][1]-1]++;
            trusts[edge[i][0]-1]++;
        }
        for(int i=0;i<n;i++){
            if(trusted[i]==n&&trusts[i]==0){
                return i+1;
            }
        }
        return -1;
    }
};