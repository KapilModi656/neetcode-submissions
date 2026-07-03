class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int target=-nums[i];
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    result.push_back({nums[i],nums[j],nums[k]});
                    while(j<n-1&& nums[j]==nums[j+1]) j++;
                    j++;
                    while(k>0&&nums[k]==nums[k-1]) k--;
                    k--;
                }
                else if(nums[j]+nums[k]<target) j++;
                else k--;
            }
        }
        return result;
    }
};
