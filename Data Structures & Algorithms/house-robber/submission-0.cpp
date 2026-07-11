class Solution {
public:
    int solve(vector<int>& nums,int i,bool flag,vector<vector<int>>& dp){
        int n=nums.size();
        if(i==n) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        int notTake = solve(nums,i+1,false,dp);
        if(flag){
            return dp[i][flag]=max(dp[i][flag],notTake);
        }
        int take = nums[i]+solve(nums,i+1,true,dp);
        return dp[i][flag] = max(dp[i][flag],max(take,notTake));
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(nums,0,false,dp);
    }
};
