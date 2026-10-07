class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sumi=0;
        int l=0;
        int ans=INT_MAX;
        for(int r=0;r<n;r++){
            sumi+=nums[r];
            while(sumi>=target){
                ans=min(ans,r-l+1);
                sumi-=nums[l];
                l++;
            }
            
        }   
        if(sumi>=target) ans=min(ans,n-l);
        if(ans==INT_MAX) return 0;
        return ans;
    }
};