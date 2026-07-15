class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    dp[j]=max(1+dp[i],dp[j]);
                    maxi = max(maxi,dp[j]);
                }
            }
        }
        return maxi;
    }
};
