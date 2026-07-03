class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m=trust.size();
        vector<int> count(n+1,0);
        for(int i=0;i<m;i++){
            int u=trust[i][0];
            int v=trust[i][1];
            count[u]--;
            count[v]++;
        }
        for(int i=1;i<=n;i++){
            if(count[i]==n-1) return i;
        }
        return -1;
    }
};