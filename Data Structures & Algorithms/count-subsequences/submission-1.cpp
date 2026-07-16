class Solution {
public:
    int solve(string& s,string& t,int i,int j,vector<vector<int>>& dp){
        int n=s.size();
        if(j==t.size()) return 1;
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = solve(s,t,i+1,j,dp);
        if(s[i]==t[j]){
            ans+=solve(s,t,i+1,j+1,dp);
        }
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        int ans =0;
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(t.size(),-1));
        ans=solve(s,t,0,0,dp);
        return ans;
    }
};
