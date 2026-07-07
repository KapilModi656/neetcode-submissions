class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        int n = nums.size();
        while(fast){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(slow==fast){
                break;
            }
        }
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
