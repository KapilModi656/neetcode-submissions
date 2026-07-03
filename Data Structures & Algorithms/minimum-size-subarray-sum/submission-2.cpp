class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sumi=0;
        int maxi=INT_MAX;
        int l=0;
        for(int r=0;r<n;r++){
            sumi+=nums[r];
            while(sumi>=target){
                maxi=min(maxi,r-l+1);
                sumi-=nums[l];
                l++;
            }
            
        }
        if(maxi==INT_MAX) return 0;
        return maxi;
        

    }
};