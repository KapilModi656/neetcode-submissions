class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++) total+=nums[i];
        vector<bool> dp(total+1,false);
        if(total%2!=0) return false;
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int j=total;j>=0;j--){
                if(j<nums[i]) continue;
                if(dp[j]) continue; 
                dp[j] = dp[j-nums[i]];
                if(dp[j]){
                    if(2*j==total){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
