class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int total=0;
        for(int i=0;i<n;i++) total+=stones[i];
        int target=total/2;
        vector<bool> dp(target+1,0);
        dp[0]=true;
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=target;j>=0;j--){
                if(stones[i]>j) continue;
                dp[j] = dp[j] | dp[j-stones[i]];
                if(dp[j]) maxi = max(maxi,j);
            }
        }
        return total-2*maxi;
    }
};