class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<=k;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second>1) return true;
        }
        for(int i=k+1;i<n;i++){
            mp[nums[i-k-1]]--;
            mp[nums[i]]++;
            if(mp[nums[i]]>1) return true;
        }
        return false;
    }
};