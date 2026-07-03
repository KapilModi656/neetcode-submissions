class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int i=0;
        int j=1;
        int n=s.size();
        unordered_map<char,int> mp;
        int maxi=1;
        mp[s[i]]++;
        while(j<n){
           while(i<=j&&mp[s[j]]!=0){
            mp[s[i]]--;
            i++;
           }
           mp[s[j]]++;
           j++;
           maxi=max(j-i,maxi);
        }
        return maxi;

    }
};
