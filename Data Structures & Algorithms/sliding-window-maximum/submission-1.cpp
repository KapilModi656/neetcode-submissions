class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(i>=k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            if(i+1>=k){
                int a = mp.rbegin()->first;
                ans.push_back(a);
            }
        }
        return ans;
    }
};
