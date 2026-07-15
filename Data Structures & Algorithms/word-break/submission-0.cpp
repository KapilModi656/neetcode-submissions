class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        map<string,bool> mp;
        for(int i=0;i<wordDict.size();i++) mp[wordDict[i]]=true;
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i=0;i<n;i++){
            string a="";
            for(int j=i;j<n;j++){
                a+=s[j];
                if(mp.count(a)){
                    dp[i][j]=true;
                    if(i!=0&&dp[0][i-1]){
                        dp[0][j]=true;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
