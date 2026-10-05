class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k&&nums[j+1]==nums[j]) j++;
                    while(k>j&&nums[k-1]==nums[k]) k--;
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]>target) k--;
                else j++;
            }
        }
        return ans;
    }
};
