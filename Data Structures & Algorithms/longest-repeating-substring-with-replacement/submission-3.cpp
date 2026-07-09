class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxi = 0;
        int max_len = 0;
        int l=0;
        char a = '1';
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(maxi<mp[s[i]]) maxi = mp[s[i]], a=s[i];
            while(i-l+1-maxi>k){
                mp[s[l]]--;
                l++;
            }
            max_len = max(i-l+1,max_len);
        }
        return max_len;
    }
};
