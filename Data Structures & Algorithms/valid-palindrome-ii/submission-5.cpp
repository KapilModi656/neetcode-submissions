class Solution {
public:
    bool isPalindrome(string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                return (isPalindrome(s,i+1,n-i-1)||isPalindrome(s,i,n-i-2));
            }
        }
        return true;
    }
};