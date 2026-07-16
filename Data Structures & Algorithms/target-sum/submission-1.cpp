class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int,int> dp;
        int n=nums.size();
        dp[0]=1;
        for(int i=0;i<n;i++){
            map<int,int> next_dp;
            for(auto& it:dp){
                int sum=it.first;
                int ways=it.second;
                next_dp[sum+nums[i]] +=ways;
                next_dp[sum-nums[i]] +=ways;
            }
            dp=next_dp;
        }
        return dp[target];
    }
};
