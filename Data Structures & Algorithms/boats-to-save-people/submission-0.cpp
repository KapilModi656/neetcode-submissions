class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0;
        int n=people.size();
        int j=n-1;
        sort(people.begin(),people.end());
        int count=0;
        while(i<j){
            if(people[i]+people[j]<=limit){
                count++;
                i++;
                j--;
            }
            else{
                j--;
                count++;
            }
        }
        if(i==j) count++;
        return count;
    }
};