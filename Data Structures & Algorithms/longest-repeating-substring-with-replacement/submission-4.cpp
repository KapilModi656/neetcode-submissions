class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxi = 0;
        int max_len = 0;
        int l=0;
        vector<int> mp(26,0);
        for(int i=0;i<n;i++){
            mp[s[i]-'A']++;
            if(maxi<mp[s[i]-'A']) maxi = mp[s[i]-'A'];
            while(i-l+1-maxi>k){
                mp[s[l]-'A']--;
                l++;
            }
            max_len = max(i-l+1,max_len);
        }
        return max_len;
    }
};
