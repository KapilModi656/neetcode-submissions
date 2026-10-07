class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char,int> count;
        int l=0;
        int maxi=0;
        for(int r=0;r<n;r++){
            count[s[r]]++;
            while(count[s[r]]>1){
                count[s[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
        }
        return maxi;
    }
};
