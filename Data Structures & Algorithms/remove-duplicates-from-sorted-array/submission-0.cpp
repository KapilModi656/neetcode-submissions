class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int w=1;
        for(int r=1;r<nums.size();r++){
            if(nums[r]!=nums[w-1]){
                nums[w]=nums[r];
                w++;
            }
        }
        return w;
    }
};