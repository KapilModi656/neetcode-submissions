class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(temp.size()==0||temp.back()<nums[i]){
                temp.push_back(nums[i]);
                continue;
            }
            auto it = lower_bound(temp.begin(),temp.end(),nums[i]);
            *it=nums[i];
        }
        return temp.size();
    }
};
