class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        map<string,bool> mp;
        for(int i=0;i<wordDict.size();i++) mp[wordDict[i]]=true;
        vector<bool> dp(n,false);
        for(int i=0;i<n;i++){
            string a="";
            for(int j=i;j<n;j++){
                a+=s[j];
                if(mp.count(a)){
                    if(i==0) dp[j]=true;
                    if(i!=0&&dp[i-1]){
                        dp[j]=true;
                    }
                }
            }
        }
        return dp[n-1];
    }
};
