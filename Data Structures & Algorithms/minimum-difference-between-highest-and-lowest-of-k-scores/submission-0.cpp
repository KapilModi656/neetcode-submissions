class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int e = k-1;
        int s=0;
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        for(int i=0;i+e<n;i++){
            mini = min(mini,nums[i+e]-nums[i+s]);
        }
        return mini;
    }
};