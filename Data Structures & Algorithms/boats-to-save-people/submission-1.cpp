class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int i=0;
        sort(people.begin(),people.end());
        int ans=0;
        for(int j=n-1;j>=i;j--){
            if(people[i]+people[j]<=limit){
                ans++;
                i++;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};