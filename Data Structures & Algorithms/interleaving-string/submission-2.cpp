class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        int n=s1.size(),m=s2.size();
        if(m==0){
            if(s1==s3) return true;
            else return false;
        }
        if(n==0){
            if(s2==s3) return true;
            else return false;
        }
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            if(s3[i-1]==s1[i-1]&&dp[i-1][0]) dp[i][0]=true;
        }
        for(int i=1;i<=m;i++){
            if(s3[i-1]==s2[i-1]&&dp[0][i-1]) dp[0][i]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int k=i+j-1;
                if(s1[i-1]==s3[k]&&dp[i-1][j]){
                    dp[i][j]=true;
                }
                else if(s2[j-1]==s3[k]&&dp[i][j-1]) dp[i][j]=true;
            }
        }
        return dp[n][m];
    }
};
