class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        if(n==0||s[0]=='0') return 0;
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]!='0'){
                dp[i]=dp[i-1];
            }
            if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6')){
                if(i>=2){
                    dp[i] += dp[i-2];
                }
                else{
                    dp[i] +=1;
                }
            }
            if(dp[i]==0) return 0;
        }
        return dp[n-1];
    }
};
