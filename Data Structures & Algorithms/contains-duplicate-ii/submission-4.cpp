class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp;
        int n=nums.size();
        int l=0;
        if(k+1>=n){
            for(int i=0;i<n;i++){
                if(mp.count(nums[i])) return true;
                mp[nums[i]]++;
            }
            return false;
        }
        for(int r=0;r<=k;r++){
            if(mp.count(nums[r])) return true;
            mp[nums[r]]++;
        }
        for(int r=k+1;r<n;r++){
            mp[nums[l]]--;
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l++;
            if(mp.count(nums[r])) return true;
            mp[nums[r]]++;
        }
        return false;
    }
};