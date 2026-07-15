class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int p=1;
        for(int i=0;i<n;i++){
            p=1;
            for(int j=i;j<n;j++){
                p=p*nums[j];
                maxi=max(maxi,p);
            }
        }
        return maxi;
    }
};
