class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int n=s.size();
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            count[s[r]-'A']++;
            int maxi = 0;
            for(int i=0;i<26;i++){
                maxi=max(maxi,count[i]);
            }
            int target = r-l+1-maxi;
            while(target>k){
                count[s[l]-'A']--;
                l++;
                int a=0;
                for(int i=0;i<26;i++){
                    a=max(a,count[i]);
                }
                target = r-l+1-a;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
