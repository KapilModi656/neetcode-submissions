class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int sumi=0;
        sort(nums.begin(),nums.end());
        int j=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            int newK = (i-j)*nums[i]-sumi;
            while(newK>k){
                sumi-=nums[j];
                j++;
                newK = (i-j)*nums[i]-sumi;
            }
            maxi = max(maxi,i-j+1); 
            sumi+=nums[i];
        }
        return maxi;
    }
};