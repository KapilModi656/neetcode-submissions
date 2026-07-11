class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int prev1=0;
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick = nums[i]+prev2;
            int notPick = prev1;
            int curr = max(pick,notPick);
            prev2=prev1;
            prev1=curr;
        }
        int ans1 = prev1;
        prev1=0;
        prev2=0;
        for(int i=0;i<n-1;i++){
            int pick = nums[i]+prev2;
            int notPick = prev1;
            int curr = max(pick,notPick);
            prev2=prev1;
            prev1=curr;
        }
        return max(ans1,prev1);
    }
};
