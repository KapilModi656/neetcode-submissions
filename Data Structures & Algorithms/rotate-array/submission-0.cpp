class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        while(k){
            for(int i=n-1;i>0;i--){
                swap(nums[i],nums[i-1]);
            }
            k--;
        }
    }
};