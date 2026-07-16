class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(3,INT_MIN));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++){
            for(int k=0;k<3;k++){
                if(k==0){
                    dp[i][k] = max(dp[i-1][k],dp[i-1][2]);
                }
                if(k==1){
                    dp[i][k] = max(-prices[i]+dp[i-1][0],dp[i-1][1]);
                }
                if(k==2){
                    dp[i][k] = max(dp[i-1][1]+prices[i],dp[i][k]);
                }
            }
        }
        return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    }
};
