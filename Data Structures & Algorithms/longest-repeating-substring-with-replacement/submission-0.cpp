class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int r=0;
        int l=0;
        int maxi=0;
        int max_freq=0;
        map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            int len=r-l+1;
            max_freq=max(max_freq,mp[s[r]]);
            while(len-max_freq>k){
                mp[s[l]]--;
                l++;
                len--;
            }
            r++;
            maxi=max(maxi,len);
        }
        return maxi;
    }
};
