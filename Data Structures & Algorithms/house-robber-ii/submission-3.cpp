#include<algorithm>
class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = nums[0]; 
        for(int i=1;i<n-1;i++){
            for(int j=0;j<2;j++){
                if(j==0){
                    dp[i][j] = max(dp[i-1][0],dp[i-1][1]);
                }
                else{
                    dp[i][j] = max(dp[i-1][0]+nums[i],dp[i-1][1]);
                }
            }
        }
        int maxi = max(dp[n-2][0],dp[n-2][1]);
        fill(dp.begin(),dp.end(),vector<int>(n,0));
        dp[1][0] = 0;
        dp[1][1] = nums[1];
        for(int i=2;i<n;i++){
            for(int j=0;j<2;j++){
                if(j==0){
                    dp[i][j] = max(dp[i-1][0],dp[i-1][1]);
                }
                else{
                    dp[i][j] = max(dp[i-1][0]+nums[i],dp[i-1][1]);
                }
            }
        }
        maxi = max(maxi,max(dp[n-1][0],dp[n-1][1]));
        return maxi;
    }
};
